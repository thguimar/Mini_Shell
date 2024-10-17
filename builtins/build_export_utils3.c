/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:12:42 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/17 18:20:55 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	export_hha(char **argv, t_builtvars *export, int j, int flag)
{
	while (argv[j][export->l - 1] != '=')
	{
		export->mlc[export->m][export->l] = argv[j][export->l];
		export->l++;
	}
	if (flag == 1)
		export->n = ft_strlen3(export->mlc[export->m]);
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

void	export_helper_helper(t_builtvars *export, char **argv, int j)
{
	int	flag;

	flag = line_waste(export, argv, 0, j);
	export->l = 0;
	if (flag == 1)
		export_hha(argv, export, j, flag);
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
