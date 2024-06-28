/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/28 17:14:14 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

int	var_equal_line_echo(char **env, char *argv)
{
	int	m;

	m = 0;
	//printf("\nESSA E A STRING: %s\n", argv);
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
			argv[j] != '"' && argv[j] != 39 && argv[j] != '$')
	{
		j++;
		i++;
	}
	//printf("tamanho da palavra: %i\n", i);
	if (i == 0 && argv[j - 1] == '$')
	{
		ft_putchar_fd ('$', 1);
		return (1);
	}
	str = ft_calloc(i + 1, sizeof(char));
	while (i >= 0)
	{
		while (argv[j] == ' ' || argv[j] == '$' || argv[j] == '"'
			|| argv[j] == 39)
		{
			i--;
			j--;
		}
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
	return (0);
}

void	skips(char *argv, int j, char **exp)
{
	int	flag;
	int	i;
	int	quotes;

	flag = 0;
	quotes = 0;
	while (argv[j])
	{
		if (argv[j] == '$' && quotes % 2 == 0)
		{
			i = echo_env(argv, j + 1, exp, 0);
			j++;
			while (argv[j] != '\0' && argv[j] != ' ' && argv[j] != '$'
				&& argv[j] != '"' && argv[j + 1] != '\'')
				j++;
			if ((argv[j] != '\0' && i == 1 && argv[j] != '$')
				|| argv[j + 1] != '\'')
				ft_putchar_fd(' ', 1);
		}
		else if (argv[j] == '"' && quotes % 2 == 0)
			flag++;
		else if (argv[j] == '\'' && flag % 2 == 0)
			quotes++;
		else
		{
			if (flag % 2 != 0 || quotes % 2 != 0)
				ft_putchar_fd(argv[j], 1);
			else
			{
				while (argv[j] && argv[j] == 32)
					j++;
				if (argv[j])
					ft_putchar_fd(argv[j], 1);
			}
				
		}
		if (argv[j] && argv[j] != '$') //se der merda testar, argv[j] || argv[j] != '$'
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
