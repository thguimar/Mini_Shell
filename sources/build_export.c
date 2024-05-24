/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:27:03 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/24 20:16:14 by thguimar         ###   ########.fr       */
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

int	ft_strlen3(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	//printf("i: %i\n", i);
	return (i);
}

int	var_equal_line(char **env, char **argv, int j)
{
	int	m;

	m = 0;
	while (env[m])
	{
		if(ft_strncmp(argv[j], env[m], ft_strlen3(argv[j])) == 0)
			return (m);
		m++;
	}
	return (0);
}

int	var_comp(char **env, char **argv, int j)
{
	int	m;

	m = 0;
	while (env[m])
	{
		if(ft_strncmp(argv[j], env[m], ft_strlen3(argv[j])) == 0)
			return (1);
		m++;
	}
	return (0);
}

int	mlc_size(int j, char **mlc)
{
	while (mlc[j])
		j++;
	return (j);
}

char	**bubble_sort(int j, char **mlc)
{
	char	*shelf;

	j = 0;
	while (mlc[j])
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
	return (mlc);
}

void	write_exp(int j, char **mlc)
{
	mlc = bubble_sort(j, mlc);
	while(mlc[j])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(mlc[j], 1);
		ft_putstr_fd("\n", 1);
		j++;
	}
	mlc[j] = NULL;
}

char	**exp_calloc(int j, char **env, int argc)
{
	int		flag;
	int		x;
	char	**mlc;
	int		i;

	j = 0;
	flag = 0;
	while(env[j + 1])
		j++;
	if (argc == 1)
		mlc = ft_calloc((j + 1), sizeof(char *));
	else
		mlc = ft_calloc((j + argc + 1), sizeof(char *));
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
	return (bubble_sort(j, mlc));
}

int	main(int argc, char **argv, char **env)
{
	int	j;
	char	**mlc;
	int	flag;

	flag = 0;
	if (argc == 1)
	{
		j = 0;
		mlc = exp_calloc(j, env, argc);
		write_exp(j, mlc);
	}
	else
	{
		int	i;
		int	x;
		int	l;
		int m;
		int	k;
		int	n;

		k = 0;
		j = 0;
		l = 0;
		x = 0;
		m = 0;
		n = 0;
		mlc = exp_calloc(j, env, argc);
		i = mlc_size(j, mlc);
		while(argv[++j])
		{
			if (var_comp(mlc, argv, 1) == 1)
			{
				m = var_equal_line(mlc, argv, 1);
				while (argv[j][l])
				{
					while (argv[j][l] == mlc[m][l] && argv[j][l])
					{
						if (argv[j][l] == '=')
						{
							mlc[m] = ft_calloc(ft_strlen(argv[j]) + 3, sizeof(char));
							l = 0;
							while(argv[j][l - 1] != '=')
							{
								mlc[m][l] = argv[j][l];
								l++;
							}
							n = ft_strlen3(mlc[m]);
							if (mlc[m][n + 1] != '"')
								mlc[m][++n] = '"';
							n++;
							while (argv[j][l])
							{
								mlc[m][n] = argv[j][l];
								n++;
								l++;
							}
							mlc[m][n] = '"';
						}
						else if (argv[j][l] == '\0')
							break ;
						if (argv[j][l] != '\0')
							l++;
					}
					if (argv[j][l] != '\0')
						l++;
				}
			}
			else
			{
				mlc[i] = ft_calloc(ft_strlen(argv[j]) + 3, sizeof(char));
				while (argv[j][l])
				{
					mlc[i][x] = argv[j][l];
					if (mlc[i][x] == '=' && flag == 0)
					{
						flag = 1;
						x++;
						mlc[i][x] = '"';
						x++;
						l++;
						if (argv[j][l] == '\0')
							mlc[i][x] = '"';
						while (argv[j][l])
						{
							mlc[i][x] = argv[j][l];
							x++;
							l++;
							if (argv[j][l] == '\0')
								mlc[i][x] = '"';
						}
					}
					if (argv[j][l] != '\0')
						l++;
					x++;
					flag = 0;
				}
				i++;
			}
		}
		j = 0;
		write_exp(j, mlc);
	}
}
