/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:02:20 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/19 20:42:47 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_cleaner(char **paths)
{
	int	i;

	i = 0;
	while (paths && paths[i])
	{
		if (i == 0)
			free(paths[i] - 5);
		else
			free(paths[i]);
		i++;
	}
	if (paths)
		free(paths);
}

void	pick_path2(t_pipe *p, char **path, int n, int i)
{
	char	*tmp;

	tmp = ft_strjoin(path[i], "/");
	if (!tmp)
	{
		path_cleaner(path);
		final_cleaner2(p);
	}
	if (p[n].command)
		p[n].path_p = ft_strjoin(tmp, p[n].command[0]);
	if (!p[n].path_p && p[n].command)
	{
		free(tmp);
		path_cleaner(path);
		final_cleaner2(p);
	}
	free(tmp);
}

char	**pick_path(char **env)
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
				path_cleaner(path);
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
			pick_path2(p, paths, n, i);
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
