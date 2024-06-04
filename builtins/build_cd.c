/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:33:47 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/04 20:58:50 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../libs/builtins.h"

char	*get_user(char **env, char *str, int j, int i)
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

int	is_twopoints(char *argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = 2;
	while (argv[i] == 46)
	{
		i++;
		flag--;
		if (flag == 0)
			return (1);
	}
	return (0);
}

char	*user_search(char **env, int i, int j, int len)
{
	char	*str;
	int		x;

	x = 1;
	while (env[j++])
	{
		while (env[j][i])
		{
			if (env[j][i] == 'U' && env[j][i + 1] == 'S'
			&& env[j][i + 2] == 'E' && env[j][i + 3] == 'R'
			&& env[j][i + 4] == '=')
			{
				i += 5;
				len = ft_strlen(&env[j][i]);
				str = ft_calloc(len + 2, sizeof(char));
				str = get_user(env, str, j, i);
				return (str);
			}
			i++;
		}
		i = 0;
	}
	return (NULL);
}

void	build_cd(int argc, char **argv, char **env)
{
	t_cd	cd;
	char	*home;

	home = "/home";
	cd.user = user_search(env, 0, 0, 0);
	home = ft_strjoin(home, cd.user);
	free(cd.user);
	cd.flag = 0;
	if (argc == 1 || argv[1][0] == '\0' || argv[1][0] == 47)
		argc_1(&cd, home, argc, argv);
	if (argc == 2)
		argc_2(&cd, argv);
	if (cd.flag == 1)
	{
		free(cd.str);
		free(cd.joined);
	}
	free(home);
}
