/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:19:40 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/10/19 20:27:28 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	echo_flag(char *argv)
{
	int	i;

	i = 1;
	if (ft_strncmp("-n", argv, 2) == 0)
	{
		while (argv[i] && argv[i] != ' ')
		{
			if (argv[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	flag_count(char *argv)
{
	int	i;

	i = 1;
	while (argv[i] == 'n')
		i++;
	while (argv[i] == ' ')
		i++;
	return (i);
}

void	has_quotes(int i, int x, char *arr, t_shell *utils)
{
	int	pa;

	utils->lala = ft_calloc(sizeof(int), 3);
	x = 0;
	if (arr[i] == '"')
	{
		i++;
		pa = 1;
		x = in_between('"', arr, i);
	}
	else if (arr[i] == '\'')
	{
		i++;
		pa = 2;
		x = in_between('\'', arr, i);
	}
	else
	{
		pa = 0;
		while (arr[i + x] && arr[i + x] != '\'' && arr[i + x] != '"')
			x++;
	}
	utils->lala[0] = pa;
	utils->lala[1] = x;
	utils->lala[2] = i;
}

void	echo_printer(t_pipe_comms *pcomms, int j, char *arr)
{
	while (pcomms->args && pcomms->args[++j])
		ft_putstr_fd(pcomms->args[j], 1);
	if (echo_flag(arr) == 0)
		ft_putstr_fd("\n", 1);
	free_dptr(pcomms->args, 0);
}

void	build_echo(char *arr, t_shell *utils, t_pipe_comms *pcomms)
{
	int		i;
	int		x;
	int		pa;
	char	*str;

	i = 0;
	if (echo_flag(arr) == 1)
		i += flag_count(arr);
	while (arr[i])
	{
		has_quotes(i, 0, arr, utils);
		i = utils->lala[2];
		pa = utils->lala[0];
		x = utils->lala[1];
		str = ft_substr(arr, i, x);
		if (pa > 0)
			i++;
		free(str);
		i += x;
	}
	utils->lala[2] = i;
	echo_printer(pcomms, 0, arr);
}
