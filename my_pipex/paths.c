/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago-campus42 <thiago-campus42@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:02:20 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/02 16:25:57 by thiago-camp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pick_path2(t_pipe *p, char **path, int n, int i)
{
	char	*tmp;

	tmp = ft_strjoin(path[i], "/");
	if (!tmp)
	{
		path_cleaner(path);
		final_cleaner(p);
	}
	if (p[n].command)
		p[n].path_p = ft_strjoin(tmp, p[n].command[0]);
	if (!p[n].path_p && p[n].command)
	{
		free(tmp);
		path_cleaner(path);
		final_cleaner(p);
	}
	free(tmp);
}

char **pick_path(char **env)
{
	char	**path;
	int		index;

	path = NULL;
	index = 0;
	while (env && env[index])
	{
		if (ft_strncmp(env[index], "PATH=", 5) == 0)
		{
			path = ft_split(env[index], ':');
			if (!path)
				free_paths(path);
			else
				path[0] = path[0] + 5;
			break ;
		}
		index++;
	}
	return (path);
}

void	search_path(t_pipe *p, char **paths)
{
	int	i;
	int	n;
	int	check;

	n = 0;
	while (++n <= p[0].n)
	{
		i = -1;
		check = 0;
		while (paths && paths[++i])
		{
			path_creator2(p, paths, n, i);
			if (p[n].path_p)
			{
				check = access(p[n].path_p, X_OK);
				if (check == 0)
					break ;
				else
					free(p[n].path_p);
			}
		}
		if ((!paths || !paths[i]) && check != 0)
			p[n].path_p = NULL;
	}
	path_cleaner(paths);
}
