/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/29 17:19:36 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
//#include "mini_shell.h"
#include "../libft/libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	echo_flag(char *argv)
{
	if (ft_strcmp("-n", argv) == 0)
		return (1);
	return (0);
}

int	echo_func(char **argv, int flag)
{
	int	j;

	j = 1;
	while (argv[j])
	{
		if (j == 1 && echo_flag(argv[j]) == 1)
		{
			j++;
			flag = 1;
		}
		if (argv[j] != NULL)
		{
			ft_putstr_fd(argv[j], 1);
			if (argv[j + 1] != NULL)
				ft_putchar_fd(' ', 1);
			else
				break ;
			j++;
		}
	}
	return (flag);
}

int	main(int argc, char **argv)
{
	int	flag;

	flag = 0;
	if (argc != 1)
	{
		flag = echo_func(argv, flag);
	}
	if (flag != 1)
		ft_putchar_fd('\n', 1);
}
