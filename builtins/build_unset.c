/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:01:10 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/04 21:58:32 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

void	struct_initialize_unset(t_builtvars2 *unset)
{
	unset->i = 0;
	unset->j = 0;
	unset->l = 0;
	unset->m = 0;
	unset->flag = 0;
	unset->clc = 0;
	unset->tries = 0;
}

void	unset_helper(t_builtvars2 *unset, char **argv, char **env)
{
	unset->m = 0;
	if (there_is_an_equal_argv(argv, env[unset->l]) == 1)
	{
		unset->clc[unset->i] = \
		ft_calloc(ft_strlen(env[unset->l]) + 1, sizeof(char));
		while (env[unset->l][unset->m])
		{
			unset->clc[unset->i][unset->m] = env[unset->l][unset->m];
			unset->m++;
		}
		unset->i++;
	}
	unset->l++;
	unset->j++;
}

char	**build_unset(int argc, char **argv, char **env)
{
	t_builtvars2	*unset;

	unset = ft_calloc(1, sizeof(t_builtvars2));
	struct_initialize_unset(unset);
	if (argc != 1)
	{
		while (argv[unset->j])
		{
			if (var_comp2(env, argv, 0) == 1)
				unset->flag++;
			unset->j++;
		}
		unset->j = 0;
		while (env[unset->j + 1])
			unset->j++;
		unset->clc = ft_calloc((unset->j + 1 - unset->flag), sizeof(char *));
		unset->j = 0;
		while (env[unset->l])
			unset_helper(unset, argv, env);
		unset->j = 0;
	}
	else
		ft_putstr_fd("\n", 1);
	return (unset->clc);
}
