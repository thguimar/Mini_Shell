/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:26:07 by thguimar          #+#    #+#             */
/*   Updated: 2023/11/17 11:26:12 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

//CHAR
char	*get_next_line(int fd);
char	*buffer_full_clear(int fd, char **buffer, char *line);
char	*ft_strjoin2(char const *str1, char const *str2);
//INT
int		next_line(char **line, char *buffer);
int		ft_strlen2(char const *str1);
//VOID
void	buffer_clear(char *buffer);
#endif
