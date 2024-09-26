/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:57:29 by thguimar          #+#    #+#             */
/*   Updated: 2024/09/03 18:06:02 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	free_dptr(char **clc, int i)
{
	//if (clc || clc[0])
	//	return ;
	if (clc && clc[i])
	{
		while (clc[i])
		{
			free(clc[i]);
			//clc[i] = NULL;
			i++;
		}
	}
	free(clc);
}

void	free_tptr(char ***clc, int i)
{
	int	j;

	if (clc && clc[i])
	{
		while (clc[i])
		{
			j = 0;
			if (clc[i][j])
			{
				while (clc[i][j])
				{
					free(clc[i][j]);
					j++;
				}
			}
			free(clc[i]);
			i++;
		}
	}
	free(clc);
}

void	ft_free(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
	}
}

void	final_cleaner(t_shell *utils)
{
	//int	i;

	//i = -1;
	free_dptr(utils->builtins, 0);
	free_dptr(utils->exp, 0);
	free_dptr(utils->command, 0);
	free_dptr(utils->envr, 0);
	free(utils->expansions);
	free(utils->export);
	free(utils);
}

t_status *global_status(void)
{
	static t_status	status;

	return (&status);
}

void	status_handler(t_shell *utils)
{
	(void)utils;
	//if (utils->status == 2)
	//	utils->status = 130;
	if (global_status()->status > 255) // se for maior que este numero, ele divide, mas mostra o exit code como o resto da divisao e nao o resultado
		global_status()->status /= 256;
}

void	build_exit(char **argv, t_shell *utils, int flag)
{
	int	i;

	i = 0;
	if (!argv[1])
	{
		//free_dptr(argv, 0);
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
