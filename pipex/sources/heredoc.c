/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:29:59 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/19 17:08:03 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	heredoc_init(t_pipe *p)
{
	char	*str;
	int		fd[2];
	
	if (pipe(fd) == -1)
		final_cleaner(p);
	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str)
			final_cleaner(p);
		if (ft_strncmp(str, p[0].limiter, ft_strlen(str)) == 0
			&& ft_strlen(str) == ft_strlen(p[0].limiter))
			break ;
		ft_putstr_fd(str, fd[1]);
		free(str);
	}
	free(str);
	close(fd[1]);
	free(p[0].limiter);
	return (fd[0]);
}
