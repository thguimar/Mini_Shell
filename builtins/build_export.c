/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:27:03 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/06 06:21:21 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"
#include "../libft/libft.h"

void	export_helper_helper(t_builtvars *export, char **argv)
{
	line_waste(export, argv, 0);
	export->l = 0;
	while (argv[export->j][export->l - 1] != '=')
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

void	export_helper(t_builtvars *export, char **argv)
{
	export->m = var_equal_line(export->mlc, argv, 1);
	while (argv[export->j][export->l])
	{
		while (argv[export->j][export->l] == \
		export->mlc[export->m][export->l] && argv[export->j][export->l])
		{
			if (argv[export->j][export->l] == '=')
				export_helper_helper(export, argv);
			else if (argv[export->j][export->l] == '\0')
				break ;
			if (argv[export->j][export->l] != '\0')
				export->l++;
		}
		if (argv[export->j][export->l] != '\0')
			export->l++;
	}
}

void	export_helper_helper2(t_builtvars *export, char **argv)
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

void	export_helper2(t_builtvars *export, char **argv)
{
	export->mlc[export->i] = \
	ft_calloc(ft_strlen(argv[export->j]) + 3, sizeof(char));
	while (argv[export->j][export->l])
	{
		export->mlc[export->i][export->x] = argv[export->j][export->l];
		if (export->mlc[export->i][export->x] == '=' && export->flag == 0)
			export_helper_helper2(export, argv);
		if (argv[export->j][export->l] != '\0')
			export->l++;
		export->x++;
		export->flag = 0;
	}
	export->i++;
}

char	**build_export(int argc, char **argv, char **env, t_shell *utils)
{
	struct_initialize_export(utils, env, argc);
	if (utils->exp != NULL)
		utils->export->mlc = utils->exp;
	if (argc == 1)
	{
		utils->export->i = mlc_size(utils->export->j, utils->export->mlc);
		write_exp(utils->export);
	}
	else
	{
		utils->export->i = mlc_size(utils->export->j, utils->export->mlc);
		while (argv[++utils->export->j])
		{
			if (var_comp(utils->export->mlc, argv, 1) == 1)
				export_helper(utils->export, argv);
			else
			{
				export_helper2(utils->export, argv);
				utils->export->mlc = bubble_joanda(0, utils->export->mlc);
			}
		}
		utils->export->j = 0;
	}
	return (utils->export->mlc);
}
