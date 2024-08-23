/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:19:40 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/23 15:22:32 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

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

int	final_reader_size(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			while (str[i] != '\'')
				i++;
		}
		else if (str[i] == '"')
		{
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

void	build_echo(char *arr, t_shell *utils, int i, int j)
{
	int		x;
	int		pa;
	char	*str;
	char	**final_reader;

	pa = 0;
	final_reader = ft_calloc(sizeof(char *), final_reader_size(arr) + 1);
	if (echo_flag(arr) == 1)
		i += flag_count(arr);
	while (arr[i])
	{
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
		str = ft_substr(arr, i, x);
		if (pa > 0)
			i++;
		final_reader[++j] = expansions(str, utils, pa);
		free(str);
		i += x;
	}
	j = -1;
	while (final_reader[++j])
		ft_putstr_fd(final_reader[j], 1);
	if (echo_flag(arr) == 0)
		ft_putstr_fd("\n", 1);
	free_dptr(final_reader, 0);
}

/* int	flag;

	flag = 0;
	if (arr)
		flag = echo_func(arr, flag);
	if (echo_flag(arr) == 1)
		arr += flag_count(arr);
	if (flag != 1)
		ft_putchar_fd('\n', 1); */