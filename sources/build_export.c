/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:27:03 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/29 16:47:12 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

void	line_waste(t_builtvars *export, char **argv, int flag)
{
	if (flag == 0)
		export->mlc[export->m] = ft_calloc(ft_strlen(argv[export->j]) + 3, sizeof(char));
	if (flag == 1)
		export->mlc[export->i] = ft_calloc(ft_strlen(argv[export->j]) + 3, sizeof(char));
}

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

char	**exp_calloc(t_builtvars *export, char **env, int argc)
{
	while(env[export->j + 1])
		export->j++;
	if (argc == 1)
		export->mlc = ft_calloc((export->j + 1), sizeof(char *));
	else
		export->mlc = ft_calloc((export->j + argc + 1), sizeof(char *));
	export->j = 0;
	while(env[export->j + 1])
	{
		export->i = 0;
		while(env[export->j][export->i])
			export->i++;
		export->mlc[export->j] = ft_calloc(export->i + 3, sizeof(char));
		export->i = 0;
		export->x = 0;
		while(env[export->j][export->x])
		{
			export->mlc[export->j][export->i] = env[export->j][export->x];
			if (export->mlc[export->j][export->i] == '=' && export->flag == 0)
			{
				export->flag = 1;
				export->i++;
				export->mlc[export->j][export->i] = '"';
			}
			export->i++;
			export->x++;
		}
		export->flag = 0;
		export->mlc[export->j][export->i] = '"';
		export->j++;
	}
	return (bubble_sort(export->j, export->mlc));
}
void	struct_initialize(t_builtvars *export, char **env, int argc)
{
	export->mlc = exp_calloc(export, env, argc);
	export->k = 0;
	export->l = 0;
	export->m = 0;
	export->n = 0;
	export->x = 0;
	export->j = 0;
	export->i = 0;
	export->flag = 0;
}

int	main(int argc, char **argv, char **env)
{
	t_builtvars *export;

	export = ft_calloc(1 , sizeof(t_builtvars));
	struct_initialize(export, env, argc);
	if (argc == 1)
		write_exp(export->j, export->mlc);
	else
	{
		export->i = mlc_size(export->j, export->mlc);
		while(argv[++export->j])
		{
			if (var_comp(export->mlc, argv, 1) == 1)
			{
				export->m = var_equal_line(export->mlc, argv, 1);
				while (argv[export->j][export->l])
				{
					while (argv[export->j][export->l] == export->mlc[export->m][export->l] && argv[export->j][export->l])
					{
						if (argv[export->j][export->l] == '=')
						{
							line_waste(export, argv, 0);
							export->l = 0;
							while(argv[export->j][export->l - 1] != '=')
							{
								export->mlc[export->m][export->l] = argv[export->j][export->l];
								export->l++;
							}
							export->n = ft_strlen3(export->mlc[export->m]);
							if (export->mlc[export->m][export->n + 1] != '"')
								export->mlc[export->m][++export->n] = '"';
							export->n++;
							while (argv[export->j][export->l])
							{
								export->mlc[export->m][export->n] = argv[export->j][export->l];
								export->n++;
								export->l++;
							}
							export->mlc[export->m][export->n] = '"';
						}
						else if (argv[export->j][export->l] == '\0')
							break ;
						if (argv[export->j][export->l] != '\0')
							export->l++;
					}
					if (argv[export->j][export->l] != '\0')
						export->l++;
				}
			}
			else
			{
				export->mlc[export->i] = ft_calloc(ft_strlen(argv[export->j]) + 3, sizeof(char));
				while (argv[export->j][export->l])
				{
					export->mlc[export->i][export->x] = argv[export->j][export->l];
					if (export->mlc[export->i][export->x] == '=' && export->flag == 0)
					{
						export->flag = 1;
						export->x++;
						export->mlc[export->i][export->x] = '"';
						export->x++;
						export->l++;
						if (argv[export->j][export->l] == '\0')
							export->mlc[export->i][export->x] = '"';
						while (argv[export->j][export->l])
						{
							export->mlc[export->i][export->x] = argv[export->j][export->l];
							export->x++;
							export->l++;
							if (argv[export->j][export->l] == '\0')
								export->mlc[export->i][export->x] = '"';
						}
					}
					if (argv[export->j][export->l] != '\0')
						export->l++;
					export->x++;
					export->flag = 0;
				}
				export->i++;
			}
		}
		export->j = 0;
		write_exp(export->j, export->mlc);
	}
}
