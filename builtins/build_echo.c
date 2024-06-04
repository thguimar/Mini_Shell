/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/04 20:45:00 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

void skips(char **argv, int j)
{
	int	i;

	i = 0;
	while(argv[j][i])
	{
		if (argv[j][i] == '"') //ISSO ESTA PULANDO AS '"' POREM QUANDO TEM APENAS
			i++;				//UMA ASPAS PRECISAMOS ABRIR O HEREDOC
		else
		{
			ft_putchar_fd(argv[j][i], 1);
			i++;
		}
	}
}

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
			skips(argv, j);
			if (argv[j + 1] != NULL)
				ft_putchar_fd(' ', 1);
			else
				break ;
			j++;
		}
	}
	return (flag);
}

void	build_echo(char **arr)
{
	int	flag;

	flag = 0;
	if (arr)
	{
		flag = echo_func(arr, flag);
	}
	if (flag != 1)
		ft_putchar_fd('\n', 1);
}
