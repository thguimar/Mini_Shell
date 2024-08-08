/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago-campus42 <thiago-campus42@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:40:59 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/02 16:05:25 by thiago-camp      ###   ########.fr       */
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
/*#  include "libft/libft.h"
#  include "get_next_line/get_next_line.h"*/

typedef struct s_pipe
{
	int		id;
	char	**command;
	char	*path_p;
	int		fd[2];
	int		n;
}		t_pipe;

char **pick_path(char **env);

# endif
#endif