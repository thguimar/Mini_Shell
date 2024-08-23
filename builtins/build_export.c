/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:33:10 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/23 20:36:50 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	export_helper2(char **mlc, char **argv, int i)
{
	int	j;

	if (!ft_isalpha(argv[i][0]))
		printf("export: `%s': not a valid identifier\n", argv[i]);
	else
	{
		j = mlc_size(0, mlc);
		mlc[j] = ft_strdup(argv[i]);
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
		if (argv[j][export->l] == '=')
			export_helper_helper(export, argv, j);
		if (argv[j][export->l] != '\0')
			export->l++;
	}
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

void	argc2(t_shell *utils, char **argv, int j, int argc)
{
	if (equal_vars(utils->exp, argv, j, 0) == 1)
	{
		if (is_there_equals(argv[j]) == 1)
		{
			utils->export->mlc = utils->exp;
			export_helper(utils->export, argv, j);
			utils->export->mlc = bubble_sort(0,
					utils->export->mlc, 1, argc);
		}
	}
	else
	{
		export_helper2(utils->exp, argv, j);
		utils->exp = bubble_sort(0, utils->exp, 1, argc);
	}
}

char	**dptr_dup(char	**dptr)
{
	char	**rtn;
	int		i;

	i = -1;
	rtn = ft_calloc(sizeof(char *), mlc_size(0, dptr) + 1);
	while (dptr[++i])
		rtn[i] = ft_strdup(dptr[i]);
	return (rtn);
}

char	**build_export(int argc, char **argv, t_shell *utils)
{
	int			j;
	static int	x;

	(void)argv;
	j = 1;
	if (argc == 1)
	{
		utils->export->i = mlc_size(0, utils->exp);
		write_exp(utils);
	}
	else
	{
		while (argv[j])
		{
			utils->exp = bubble_sort(0, utils->exp, 1, argc);
			argc2(utils, argv, j, argc);
			index_reset(utils);
			j++;
		}
	}
	if (x == 1)
		free_dptr(utils->envr, 0);
	x = 1;
	utils->envr = dptr_dup(utils->exp);
	return (utils->exp);
}
