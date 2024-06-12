/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:33:10 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/12 17:07:17 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	mlc_size(int j, char **mlc)
{
	while (mlc[j])
		j++;
	return (j);
}

int	ft_strcmp2(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		//printf("*s1: %s\n*s2: %s\n", s1, s2);
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	**exp_copy2(char **exp)
{
	int		i;
	int		j;
	char	**copy;

	i = -1;
	j = -1;
	copy = ft_calloc(mlc_size(0, exp) + 2, sizeof(char *));
	while (exp[++j])
	{
		copy[j] = ft_calloc(ft_strlen(exp[j]) + 1, sizeof(char));
		while(exp[j][++i])
			copy[j][i] = exp[j][i];
		i = -1;
	}
	return (copy);
}

char	**exp_copy(char **exp)
{
	int		i;
	int		j;
	char	**copy;

	i = -1;
	j = -1;
	copy = ft_calloc(mlc_size(0, exp) + 1, sizeof(char *));
	while (exp[++j + 1])
	{
		copy[j] = ft_calloc(ft_strlen(exp[j]) + 1, sizeof(char));
		while(exp[j][++i])
			copy[j][i] = exp[j][i];
		i = -1;
	}
	return (copy);
}

char	**bubble_sort(int j, char **mlc, int flag)
{
	char	**copy;
	char	*shelf;
	int		i = 0;

	if (flag == 0)
		copy = exp_copy(mlc);
	else
		copy = exp_copy2(mlc);
	j = 0;
	while (copy[j])
	{
		if ((copy[j + 1] != NULL && copy[j] != NULL) &&
			ft_strcmp2(copy[j], copy[j + 1]) > 0)
		{
			shelf = copy[j];
			copy[j] = copy[j + 1];
			copy[j + 1] = shelf;
			j = -1;
			i = -1;
		}
		i++;
		j++;
	}
	return (copy);
}

void	write_exp(t_shell *utils)
{
	int	j;
	int	i;
	int	flag;

	j = 0;
	i = 0;
	flag = 0;
	while (utils->exp[j])
	{
		ft_putstr_fd("declare -x ", 1);
		while (utils->exp[j][i])
		{
			if (utils->exp[j][i - 1] == '=' && flag == 0)
			{
				flag = 1;
				ft_putchar_fd('"', 1);
			}
			ft_putchar_fd(utils->exp[j][i], 1);
			i++;
			if (flag == 1 && utils->exp[j][i] == '\0')
			{
				ft_putchar_fd('"', 1);
				flag = 0;
			}
		}
		ft_putstr_fd("\n", 1);
		i = 0;
		j++;
	}
	utils->exp[j] = NULL;
}

int	ft_strlen3(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	return (i);
}

int	var_equal_line(char **env, char **argv, int j)
{
	int	m;

	m = 0;
	while (env[m])
	{
		if (ft_strncmp(argv[j], env[m], ft_strlen3(argv[j])) == 0)
			return (m);
		m++;
	}
	return (0);
}

int	line_waste(t_builtvars *export, char **argv, int flag, int j)
{
	int	i;

	i = 0;
	free(export->mlc[export->m]);
	if (flag == 0)
		export->mlc[export->m] = \
		ft_calloc(ft_strlen(argv[export->j]) + 1, sizeof(char));
	if (flag == 1)
		export->mlc[export->i] = \
		ft_calloc(ft_strlen(argv[export->j]) + 1, sizeof(char));
	if (j >= 0)
	{
		while (argv[j][i++])
		{
			if (argv[j][i] == '=')
				flag = 1;
		}
	}
	return (flag);
}

void	export_helper2(t_builtvars *export, char **argv, int i)
{
	int	j;
	
	if (!ft_isalpha(argv[i][0]))
		printf("export: `%s': not a valid identifier\n", argv[i]);
	else
	{
		j = mlc_size(0, export->mlc);
		export->mlc[j] = ft_strdup(argv[i]);
	}
}

void	export_helper_helper(t_builtvars *export, char **argv, int j)
{
	int	flag;

	flag = line_waste(export, argv, 0, j);
	export->l = 0;
	while (argv[j][export->l - 1] != '=' || argv[j][export->l])
	{
		export->mlc[export->m][export->l] = argv[j][export->l];
		export->l++;
	}
	printf("...\n");
	if (flag == 1)
	{
		printf("FLAG -> %i\n", flag);
		export->n = ft_strlen3(export->mlc[export->m]);
	}
	else
		export->n = ft_strlen(export->mlc[export->m]);
	if (argv[j][export->l] != '"')
		export->n++;
	while (argv[j][export->l + 1] == '"')
		export->l++;
	while (argv[j][export->l])
	{
		if (argv[j][export->l] != '"')
			export->mlc[export->m][export->n] = argv[j][export->l];
		export->n++;
		export->l++;
	}
}

void	export_helper(t_builtvars *export, char **argv, int j)
{
	export->m = var_equal_line(export->mlc, argv, j);
	while (argv[j][export->l])
	{
		while (argv[j][export->l] == \
		export->mlc[export->m][export->l] && argv[j][export->l])
		{
			if (ft_strlen3(argv[j]) == 1)
				export_helper_helper(export, argv, j);
			else
			{
				if (argv[j][export->l] == '=')
					export_helper_helper(export, argv, j);
				else if (argv[j][export->l] == '\0')
					break ;
				if (argv[j][export->l] != '\0')
					export->l++;
			}
		}
		if (argv[j][export->l] != '\0')
			export->l++;
	}
}

int	equal_vars(char **exp, char **argv, int j)
{
	int	m;

	m = 0;
	while (exp[m + 1])
	{
		if (ft_strlen3(argv[j]) > ft_strlen3(exp[m]))
		{
			if (ft_strncmp(argv[j], exp[m], ft_strlen3(argv[j])) == 0)
				return (1);
			m++;
		}
		else
		{
			if (ft_strncmp(argv[j], exp[m], ft_strlen3(exp[m])) == 0)
				return (1);
			m++;
		}

	}
	return (0);
}

char	**build_export(int argc, char **argv, t_shell *utils)
{
	int	j;
	
	(void)argv;
	j = 1;
	if (argc == 1)
	{
		utils->export->i = mlc_size(0, utils->exp);
		write_exp(utils);
	}
	else
	{
		while(argv[j])
		{
			if (equal_vars(utils->exp, argv, j) == 1)
			{
				utils->export->mlc = utils->exp;
				export_helper(utils->export, argv, j);
				utils->export->mlc = bubble_sort(0, utils->export->mlc, 1);
			}
			else
			{
				utils->export->mlc = utils->exp;
				export_helper2(utils->export, argv, j);
				utils->exp = bubble_sort(0, utils->export->mlc, 1);
			}
			index_reset(utils);
			j++;
		}
	}
	return (utils->exp);
}
/*if !minishell
	if (pebonito)
		vender pack do pe
	else
		trafico*/ 
