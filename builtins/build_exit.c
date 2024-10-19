/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:57:29 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/19 20:29:19 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

t_status	*global_status(void)
{
	static t_status	status;

	return (&status);
}
// se for maior que este numero, ele divide, mas mostra o exit
//code como o resto da divisão e não o quociente

void	status_handler(t_shell *utils)
{
	(void)utils;
	if (global_status()->status > 255)
		global_status()->status /= 256;
}

void	free_dptr(char **clc, int i)
{
	if (clc && clc[i])
	{
		while (clc[i])
		{
			free(clc[i]);
			i++;
		}
	}
	free(clc);
}

void	final_cleaner(t_shell *utils)
{
	free_dptr(utils->builtins, 0);
	free_dptr(utils->exp, 0);
	free_dptr(utils->command, 0);
	free_dptr(utils->envr, 0);
	free(utils->expansions);
	free(utils->export);
	free(utils);
}

void	build_exit(char **argv, t_shell *utils, int flag, int i)
{
	if (!argv[1])
	{
		if (flag == 1)
			ft_putendl_fd("exit", 1);
		final_cleaner(utils);
		exit (global_status()->status);
	}
	if (!argv[2])
	{
		while (ft_isdigit(argv[1][i]) == 1)
			i++;
		if (argv[1][i] != '\0')
		{
			free_dptr(argv, 0);
			exit (2);
		}
		else
		{
			global_status()->status = ft_atoi(argv[1]);
			final_cleaner(utils);
			exit (global_status()->status);
		}
	}
	else
		ft_putendl_fd("Too many arguments", 1);
}
