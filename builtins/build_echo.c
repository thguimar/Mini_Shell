/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago-campus42 <thiago-campus42@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:19:40 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/07/16 18:11:02 by thiago-camp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

int	echo_flag(char *argv)
{
	if (ft_strncmp("-n", argv, 2) == 0)
	{
		if (argv[2] == 32 || argv[2] == 'n')
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

int	echo_func(char *argv, int flag/*, char **exp*/)
{
	int	j;

	j = 0;
	if (j == 0 && echo_flag(argv) == 1)
	{
		flag = 1;
		j += flag_count(argv);
	}	
	return (flag);
}

void	build_echo(char *arr/*, char **exp*/)
{
	int	flag;

	flag = 0;
	if (arr)
		flag = echo_func(arr, flag/*, exp*/);
	quotes(arr);
	if (flag != 1)
		ft_putchar_fd('\n', 1);
}