/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:22:26 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/13 22:42:31 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"
#include "../libs/builtins.h"
#include "../libft/libft.h"

int	compare_exp_env(t_shell *utils, int i, int j)
{
	while (utils->envr[i])
	{
		if (ft_strcmp2(utils->exp[j], utils->envr[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	write_exp_to_env(t_shell *utils, int i, int j)
{
	while (j > -1)
	{
		while (utils->exp[j][i])
		{
			if (utils->exp[j][i] == '=' && compare_exp_env(utils, 0, j) == 1)
			{
				ft_putstr_fd(utils->exp[j], 1);
				ft_putstr_fd("\n", 1);
				break ;
			}
			i++;
		}
		j--;
		i = 0;
	}
}

void	build_env(int argc, char **argv, t_shell *utils)
{
	int	j;

	j = 0;
	(void)argv;
	if (argc == 1)
	{
		while (utils->envr[j])
		{
			ft_putstr_fd(utils->envr[j], 1);
			ft_putstr_fd("\n", 1);
			j++;
		}
		write_exp_to_env(utils, 0, mlc_size(0, utils->exp) - 1);
	}
}
