/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago-campus42 <thiago-campus42@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:29:59 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/16 01:19:48 by thiago-camp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	heredoc_init(t_pipe *p)
{
	char	*str;
	int		fd[2];
	
	if (pipe(fd) == -1)
		ft_putstr_fd("colocar erro aqui\n", 1);
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		//if (!str)
		//	saida aqui;
		if (ft_strncmp(str, p[0].limiter, ft_strlen(str) - 1) == 0
			&& (ft_strlen(str) - 1) == ft_strlen(p[0].limiter))
			break ;
		ft_putstr_fd(str, fd[1]);
		free(str);
	}
	free(str);
	close(fd[1]);
	free(p[0].limiter);
	return (fd[0]);
}
