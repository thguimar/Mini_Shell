/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:19:40 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/19 20:55:31 by joanda-s         ###   ########.fr       */
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
		while (argv[i] != ' ')
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

void	build_echo(char *arr)
{
	int	flag;

	flag = 0;
	if (arr)
		flag = echo_func(arr, flag);
	if (echo_flag(arr) == 1)
		arr += flag_count(arr);
	if (flag != 1)
		ft_putchar_fd('\n', 1);
}
