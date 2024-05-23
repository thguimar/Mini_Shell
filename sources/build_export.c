/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:27:03 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/23 17:55:53 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../libft/libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	**env_calloc(int j, char **env)
{
	int		flag;
	int		x;
	char	**mlc;
	int		i;

	j = 0;
	flag = 0;
	while(env[j + 1])
		j++;
	mlc = ft_calloc((j + 1), sizeof(char *));
	j = 0;
	while(env[j + 1])
	{
		i = 0;
		while(env[j][i])
			i++;
		mlc[j] = ft_calloc(i + 3, sizeof(char));
		i = 0;
		x = 0;
		while(env[j][x])
		{
			mlc[j][i] = env[j][x];
			if (mlc[j][i] == '=' && flag == 0)
			{
				flag = 1;
				i++;
				mlc[j][i] = '"';
			}
			i++;
			x++;
		}
		flag = 0;
		mlc[j][i] = '"';
		j++;
	}
	return (mlc);
}

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc == 1)
	{
		int		j;
		char	*shelf;
		char	**mlc;

		j = 0;
		mlc = env_calloc(j, env);
		while(mlc[j])
		{
			if (mlc[j + 1] != NULL && mlc[j] != NULL && ft_strcmp(mlc[j], mlc[j + 1]) > 0)
			{
				shelf = mlc[j];
				mlc[j] = mlc[j + 1];
				mlc[j + 1] = shelf;
				j = 0;
			}
			j++;
		}
		printf(".\n");
		j = 0;
		while(mlc[j])
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(mlc[j], 1);
			ft_putstr_fd("\n", 1);
			j++;
		}
		mlc[j] = NULL;
	}
}
