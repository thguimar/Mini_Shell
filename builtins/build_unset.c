/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:24:33 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/10/19 20:32:34 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	ft_strlen4(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1] != '=')
		i++;
	return (i);
}

int	var_equal_line2(char **env, char *argv)
{
	int	m;

	m = 0;
	while (env[m])
	{
		if (ft_strncmp(argv, env[m], ft_strlen3(env[m])) == 0)
			return (m);
		m++;
	}
	return (-1);
}

int	unset_argv_checker(char *exp, char **argv)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if (ft_strncmp(exp, argv[j], ft_strlen4(argv[j])) == 0)
			return (1);
		j++;
	}
	return (0);
}

int	unset_flag(int flag, char *exp, char *argv)
{
	int	sla;

	sla = ft_strncmp(exp, argv, ft_strlen4(argv));
	if (sla == 0)
		flag++;
	return (flag);
}

char	**build_unset(int argc, char **argv, char **exp, int i)
{
	int		j;
	char	**copy;
	int		flag;

	j = -1;
	flag = 0;
	if (argc > 1)
	{
		while (argv[++j])
		{
			while (exp[++i])
				flag = unset_flag(flag, exp[i], argv[j]);
			i = -1;
		}
		j = -1;
		copy = ft_calloc(mlc_size(0, exp) - flag + 1, sizeof(char *));
		while (exp[++i])
		{
			if (unset_argv_checker(exp[i], argv) == 0)
				copy[++j] = ft_strdup(exp[i]);
		}
		free_dptr(exp, 0);
		exp = copy;
	}
	return (global_status()->status = 0, exp);
}
