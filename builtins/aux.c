/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:56:34 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/09 18:21:46 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"

void	ft_free_pid(char **pid)
{
	int	i;

	i = 0;
	if (*pid == NULL)
		return ;
	while (pid[i])
	{
		free(pid[i]);
		i++;
	}
	free(pid);
}

char	*ft_getpid(void)
{
	char		*pid;
	int			fd;
	char		**temp;

	fd = open("/proc/self/stat", O_RDONLY);
	if (!fd)
		return (NULL);
	pid = get_next_line(fd);
	if (!pid)
		return (NULL);
	temp = ft_split(pid, ' ');
	free(pid);
	if (!temp)
		return (NULL);
	pid = ft_strdup(temp[0]);
	ft_free_pid(temp);
	if (!pid)
		return (NULL);
	return (pid);
}
/*int main (void)
{
	char	*temp;

	temp = ft_getpid();
	printf("pid: %s\n", temp);
	free(temp);
}*/