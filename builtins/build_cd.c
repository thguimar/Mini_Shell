/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:33:47 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/19 20:23:16 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

char	*get_user(char **env, char *str, int i, int j)
{
	int	x;

	x = 1;
	while (env[j][i])
	{
		str[0] = '/';
		str[x++] = env[j][i++];
	}
	return (str);
}

char	*user_search(char **env, int i, int j, int len)
{
	char	*str;

	while (env[j++])
	{
		while (env[j] && env[j][i])
		{
			if (ft_strncmp("USER=", env[j], 5) == 0)
			{
				i += 5;
				len = ft_strlen(env[j]) - 5;
				str = ft_calloc(len + 2, sizeof(char));
				str = get_user(env, str, i, j);
				return (str);
			}
			i++;
		}
		i = 0;
	}
	return (NULL);
}

void	cd_initialize(t_cd *cd, t_shell *utils)
{
	cd->user = NULL;
	cd->flag = -1;
	cd->str = NULL;
	cd->joined = NULL;
	cd->i = 0;
	cd->j = 0;
	cd->x = 0;
	cd->utils = utils;
}

void	build_cd(int argc, char **argv, char **env, t_shell *utils)
{
	t_cd	cd;
	char	*home;

	(void)argc;
	global_status()->status = 0;
	cd_initialize(&cd, utils);
	home = "/home";
	cd.user = user_search(env, 0, 0, 0);
	if (cd.user)
		home = ft_strjoin(home, cd.user);
	free(cd.user);
	cd.flag = 0;
	argc_2(&cd, argv, utils);
	if (cd.flag == 1)
	{
		free(cd.str);
		free(cd.joined);
	}
	if (home && ft_strncmp("/home", home, 6) != 0)
		free(home);
}
