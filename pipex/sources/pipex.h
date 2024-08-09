/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:40:59 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/09 13:25:46 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef PATH
#  define PATH "/home/thguimar/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"

#  include <string.h>
#  include <stdlib.h>
#  include <unistd.h>
#  include <stdio.h>
#  include <fcntl.h>
#  include <stddef.h>
#  include <sys/types.h>
#  include <sys/wait.h>
#  include "../../libft/libft.h"

typedef struct s_pipe
{
	int		id;
	char	**command;
	char	*path_p;
	int		fd[2];
	int		n;
}		t_pipe;

char 	**pick_path(char **env);
void	search_path(t_pipe *p, char **paths);
void	exec_fork(t_pipe *p, char **env);
void	fd_shut(t_pipe *p, int n);
void	free_p(t_pipe *p);
void	final_cleaner(t_pipe *p);
void	error_handler(t_pipe *p, int n, int type);
void	path_cleaner(char **paths);

# endif
#endif
