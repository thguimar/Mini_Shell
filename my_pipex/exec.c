/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago-campus42 <thiago-campus42@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:58:21 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/02 17:14:34 by thiago-camp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(t_pipe *p, char **env, int n)
{
	if (dup2(p[n - 1].fd[0], STDIN_FILENO) == -1)
		error(p, NULL, 0, 1);
	if (n == p[0].n)
	{
		if (dup2(p[0].fd[1], STDOUT_FILENO) == -1)
			error_msg(p, NULL, 0, 1);
	}
	else
	{
		if (dup2(p[n].fd[1], STDOUT_FILENO) == -1)
			error_msg(p, NULL, 0, 1);
	}
	close_fd(p, p[0].n);
	if (execve(p[n].path_p, p[n].command, env) == -1)
		fancy_exit(p);
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
				final_cleaner(p);
			if (p[n].id == 0)
			{
				if (access(p[n].path_p, X_OK) == 0)
					exec_command(p, env, n);
				break ;
			}
		}
		if ((!p[n].path_p || !p[n].path_p[0]) && p[n].command)
			-> error <-;
	}
	close_fd(p, p[0].n);
}