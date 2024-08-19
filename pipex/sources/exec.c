/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:58:21 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/19 20:42:47 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	any_here_doc(char **argv)
{
	if (ft_strncmp(argv[1], "heredoc", 7) == 0)
		return (1);
	return (0);
}

void	fd_detector(t_pipe *p, char **argv, int argc, int i)
{
	int	n;

	if (p[0].heredoc == false)
	{
		p[i].fd[0] = open(argv[argc - 5], O_RDONLY);
		p[i].fd[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	else
	{
		p[0].fd[0] = heredoc_init(p);
		p[0].fd[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	if (p[0].fd[1] == -1)
		final_cleaner2(p);
	if (p[0].fd[0] == -1)
		error_handler(p, 0, 2);
	n = 1;
	while (n < p[0].n)
	{
		if (pipe(p[n].fd) == -1)
			final_cleaner2(p);
		n++;
	}
}

void	fd_shut(t_pipe *p, int n)
{
	int	x;

	x = 0;
	while (x < n)
	{
		if (p[x].fd[0] != -1 && p[x].fd[0] != STDIN_FILENO
			&& p[x].fd[0] != STDOUT_FILENO && p[x].fd[0] != STDERR_FILENO)
			close(p[x].fd[0]);
		if (p[x].fd[1] != -1 && p[x].fd[1] != STDIN_FILENO
			&& p[x].fd[1] != STDOUT_FILENO && p[x].fd[1] != STDERR_FILENO)
			close(p[x].fd[1]);
		x++;
	}
}

void	exec_command(t_pipe *p, char **env, int n)
{
	if (dup2(p[n - 1].fd[0], STDIN_FILENO) == -1)
		error_handler(p, 0, 1);
	if (n == p[0].n)
	{
		if (dup2(p[0].fd[1], STDOUT_FILENO) == -1)
			error_handler(p, 0, 1);
	}
	else
	{
		if (dup2(p[n].fd[1], STDOUT_FILENO) == -1)
			error_handler(p, 0, 1);
	}
	fd_shut(p, p[0].n);
	if (execve(p[n].path_p, p[n].command, env) == -1)
		final_cleaner2(p);
}

void	exec_fork(t_pipe *p, char **env)
{
	int	n;

	n = 0;
	while (++n <= p[0].n)
	{
		if (p[n].path_p)
		{
			p[n].id = fork();
			if (p[n].id == -1)
				final_cleaner2(p);
			if (p[n].id == 0)
			{
				if (access(p[n].path_p, X_OK) == 0)
					exec_command(p, env, n);
				break ;
			}
		}
		if ((!p[n].path_p || !p[n].path_p[0]) && p[n].command)
			error_handler(p, n, 0);
	}
	fd_shut(p, p[0].n);
}
