/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:25:38 by joana             #+#    #+#             */
/*   Updated: 2024/06/18 20:19:17 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	write_exp(t_shell *utils)
{
	int	j;
	int	i;
	int	flag;
	int	flag2;

	j = -1;
	i = 0;
	flag = 0;
	while (utils->exp[++j])
	{
		ft_putstr_fd("declare -x ", 1);
		while (utils->exp[j][i])
			flag2 = write_exp_helper(utils, i, j, flag);
		if (flag2 == 0 && is_there_equals(utils->exp[j]) == 1)
		{
			ft_putchar_fd('"', 1);
			ft_putchar_fd('"', 1);
		}
		ft_putstr_fd("\n", 1);
		i = 0;
	}
	utils->exp[j] = NULL;
}

int	write_exp_helper(t_shell *utils, int i, int j, int flag)
{
	int	flag2;

	flag2 = 0;
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
		flag2 = 1;
	}
	return (flag2);
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

int	equal_vars(char **exp, char **argv, int j, int flag)
{
	int	m;

	m = 0;
	while (exp[m + flag])
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
