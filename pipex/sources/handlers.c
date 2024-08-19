/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:54:47 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/19 16:59:28 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup2(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\n';
	i++;
	str[i] = '\0';
	return (str);
}

void	error_handler(t_pipe *p, int n, int type)
{
	if (type == 0)
	{
		p[n].path_p = NULL;
		ft_putstr_fd("Command not found\n", 2);
	}
	else if (type == 1)
	{
		fd_shut(p, p[0].n);
		free_p(p);
		exit(EXIT_FAILURE);
	}
	else if (type == 2)
		ft_putstr_fd("no such file or directory\n", 2);
	else if (type == 3)
	{
		p[n].path_p = NULL;
		free (p[n].command);
		p[n].command = NULL;
		ft_putstr_fd("no such command\n", 2);
	}
}

void	final_cleaner(t_pipe *p)
{
	if (p[0].fd[0] != -1 && p[0].fd[0] != STDIN_FILENO
		&& p[0].fd[0] != STDOUT_FILENO && p[0].fd[0] != STDERR_FILENO)
		close(p[0].fd[0]);
	if (p[0].fd[1] != -1 && p[0].fd[1] != STDIN_FILENO
		&& p[0].fd[1] != STDOUT_FILENO && p[0].fd[1] != STDERR_FILENO)
		close(p[0].fd[1]);
	ft_putstr_fd("Error", 1);
	free_p(p);
	exit(EXIT_FAILURE);
}