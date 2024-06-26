/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/26 20:39:24 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

int	var_equal_line_echo(char **env, char *argv)
{
	int	m;

	m = 0;
	while (env[m])
	{
		if (ft_strncmp(argv, env[m], ft_strlen4(argv)) == 0)
			return (m);
		m++;
	}
	return (-1);
}

int	echo_env(char *argv, int j, char **exp, int i)
{
    char	    *str;
    int 		variavel;

    variavel = 0;
    while (argv[j] != '\0' && argv[j] != ' ' &&
			argv[j] != '"' && argv[j++] != 39)
		i++;
	if (i == 0 && argv[j - 1] == '$')
	{
		ft_putchar_fd ('$', 1);
		return (1);
	}
	str = ft_calloc(i + 1, sizeof(char));
	while (i >= 0)
	{
		if (str[j] == ' ')
		{
			i--;
			j--;
		}
		else
			str[i--] = argv[j--];
	}
	variavel = var_equal_line_echo(exp, str);
	free(str);
    if (variavel != -1)
    {
		i = ft_strlen3(exp[variavel]) + 1;
	    while (exp[variavel][i])
		    ft_putchar_fd(exp[variavel][i++], 1);
		return (1);
	}
	//printf("\nnao funfou a: %s\n", str); testar: export a=1 b=2 c=3 d=4, echo $a $b $c $d.
	return (0);
}

void	skips(char *argv, int j, char **exp)
{
	int	flag;
	int	i;

	flag = 0;
	while (argv[j])
	{
		if (argv[j] == '$')
		{
			i = echo_env(argv, j + 1, exp, 0);
			while (argv[j] != '\0' && argv[j] != ' ')
				j++;
			if (argv[j] != '\0' && i == 1)
				ft_putchar_fd(' ', 1);
		}
		else if ((argv[j] == '"' || argv[j] == 39))
			flag++;
		else
		{
			if (flag % 2 != 0)
				ft_putchar_fd(argv[j], 1);
			else
			{
				while (argv[j] && argv[j] == 32)
					j++;
				if (argv[j])
					ft_putchar_fd(argv[j], 1);
			}
		}
		if (argv[j])
			j++;
	}
}

int	echo_flag(char *argv)
{
	if (ft_strncmp("-n", argv, 2) == 0)
	{
		if (argv[2] == 32 || argv[2] == 'n')
			return (1);
	}
	return (0);
}

int	flag_conut(char *argv)
{
	int	i;

	i = 1;
	while (argv[i] == 'n')
		i++;
	while (argv[i] == ' ')
		i++;
	return (i);
}

int	echo_func(char *argv, int flag, char **exp)
{
	int	j;

	j = 0;
	if (j == 0 && echo_flag(argv) == 1)
	{
		flag = 1;
		j += flag_conut(argv);
	}	
	if (argv[j] != '\0')
		skips(argv, j, exp);
	return (flag);
}

void	build_echo(char *arr, char **exp)
{
	int	flag;

	flag = 0;
	if (arr)
	{
		flag = echo_func(arr, flag, exp);
	}
	if (flag != 1)
		ft_putchar_fd('\n', 1);
}
