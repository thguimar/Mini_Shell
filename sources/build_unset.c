/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:01:10 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/27 17:22:25 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../libft/libft.h"

void	write_env(int j, char **mlc)
{
//	mlc = bubble_sort(j, mlc);
	while(mlc[j])
	{
		ft_putstr_fd(mlc[j], 1);
		ft_putstr_fd("\n", 1);
		j++;
	}
	mlc[j] = NULL;
}

int	ft_strlen4(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1] != '=' && str[i])
		i++;
	//printf("i: %i\n", i);
	return (i);
}

int	there_is_an_equal_argv(char **argv, char *env)
{
	int	j;
	
	j = 0;
	while (argv[j])
	{
		if (ft_strncmp(argv[j], env, ft_strlen4(env)) == 0)
			return (0);
		j++;
	}
	return (1);
}

int	var_equal_line(char **env, char *argv)
{
	int	m;

	m = 0;
	while (env[m])
	{
		if(ft_strncmp(argv, env[m], ft_strlen(argv)) == 0)
			return (m);
		m++;
	}
	return (0);
}

int	var_comp(char **env, char **argv, int j)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if(ft_strncmp(argv[j], env[i], ft_strlen(argv[j])) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	if (argc != 1)
	{
		int		j;
		int		flag;
		char	**clc;
		int		i;
		int		m;
		int		l;
		int		tries;

		tries = 0;
		j = 0;
		flag = 0;
		i = 0;
		m = 0;
		l = 0;
		while (argv[j])
		{
			if (var_comp(env, argv, 0) == 1)
				flag++;
			j++;
		}
		j = 0;
		while(env[j + 1])
			j++;
		clc = ft_calloc((j + 1 - flag), sizeof(char *));
		j = 0;
		while (env[l])
		{
			m = 0;
			if (there_is_an_equal_argv(argv, env[l]) == 1)
			{
				clc[i] = ft_calloc(ft_strlen(env[l]) + 1, sizeof(char));
				while(env[l][m])
				{
					clc[i][m] = env[l][m];
					m++;
				}
				i++;
			}
			l++;
			j++;
		}
		j = 0;
		write_env(0, clc);
	}
	else
		ft_putstr_fd("\n", 1);
}
