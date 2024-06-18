/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:33:10 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/18 20:15:33 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	export_helper2(t_builtvars *export, char **argv, int i)
{
	int	j;

	if (!ft_isalpha(argv[i][0]))
		printf("export: `%s': not a valid identifier\n", argv[i]);
	else
	{
		j = mlc_size(0, export->mlc);
		export->mlc[j] = ft_strdup(argv[i]);
		printf("mlc_size(0, export->mlc): %i\n", mlc_size(0, export->mlc));
	}
}

void	export_helper_helper(t_builtvars *export, char **argv, int j)
{
	int	flag;

	flag = line_waste(export, argv, 0, j);
	export->l = 0;
	if (flag == 1)
	{
		while (argv[j][export->l - 1] != '=')
		{
			export->mlc[export->m][export->l] = argv[j][export->l];
			export->l++;
		}
		if (flag == 1)
			export->n = ft_strlen3(export->mlc[export->m]);
	}
	else
		export->n = ft_strlen(export->mlc[export->m]);
	if (argv[j][export->l] != '"' && flag == 1)
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
		if (argv[j][export->l] == '=')
			export_helper_helper(export, argv, j);
		if (argv[j][export->l] != '\0')
			export->l++;
	}
}

void	export_sos(t_shell *utils, char **argv, int j, int argc)
{
	if (equal_vars(utils->exp, argv, j) == 1)
	{
		if (is_there_equals(argv[j]) == 1)
		{
			utils->export->mlc = utils->exp;
			export_helper(utils->export, argv, j);
			utils->export->mlc = bubble_sort(0, utils->export->mlc, 1, argc);
		}
	}
	else
	{
		utils->export->mlc = utils->exp;
		export_helper2(utils->export, argv, j);
		utils->exp = bubble_sort(0, utils->export->mlc, 1, argc);
	}
	index_reset(utils);
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
		while (argv[j++])
			export_sos(utils, argv, j, argc);
	}
	return (utils->exp);
}
