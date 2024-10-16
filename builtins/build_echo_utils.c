/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:17:04 by joana             #+#    #+#             */
/*   Updated: 2024/10/16 17:17:36 by joana            ###   ########.fr       */
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

int	echo_func(char *argv, int flag)
{
	if (echo_flag(argv) == 1)
		flag = 1;
	return (flag);
}

int	final_reader_size(char *str, int i, int x)
{
	while (str && str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
				i++;
		}
		else if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
				i++;
		}
		else
		{
			while (str[i] && str[i] != '\'' && str[i] != '"')
				i++;
		}
		if (str[i] == '\'' || str[i] == '"')
			i++;
		x++;
	}
	return (x);
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