/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago-campus42 <thiago-campus42@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/07/16 15:59:34 by thiago-camp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

int	var_equal_line_echon(char **env, char *argv, int n)
{
	int	m;

	m = 0;
	if (n <= 0)
		return (-1);
	while (env[m])
	{

		if (ft_strncmp(argv, env[m], n) == 0)
		{
			return (m);
		}
		m++;
	}
	return (-1);
}

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

    variavel = -1;
    while (argv[j] != '\0' && argv[j] != ' ' &&
			argv[j] != '"' && argv[j] != '\'' && argv[j] != '$')
	{
		j++;
		i++;
	}
	if (i == 0 && argv[j - 1] == '$')
	{
		if (argv[j] != '\'' && argv[j] != '"')
			ft_putchar_fd ('$', 1);
		return (0);
	}
	str = ft_calloc(i + 1, sizeof(char));
	while (i >= 0)
	{
		while (argv[j] == ' ' || argv[j] == '$' || argv[j] == '"'
			|| argv[j] == '\'')
		{
			i--;
			j--;
		}
		str[i--] = argv[j--];
	}
	j = 0;
	variavel = var_equal_line_echo(exp, str);
    if (variavel != -1)
    {
		i = ft_strlen3(exp[variavel]) + 1;
	    while (exp[variavel][i])
		    ft_putchar_fd(exp[variavel][i++], 1);				/* TRANSFORMAR ESSE IF EM FUNCAO PQ LA EM BAIXO FAZ A MESMA COISA*/
		free(str);
		return (0);
	}
	else
	{
		i = 0;
		while (alpha_num(str[i]) == 1)
			i++;
		variavel = var_equal_line_echon(exp, str, i);
		if (variavel != -1)
		{
			i = ft_strlen3(exp[variavel]) + 1;
			while (exp[variavel][i])							/* TRANSFORMAR ESSE IF EM FUNCAO PQ LA EM CIMA FAZ A MESMA COISA*/
			ft_putchar_fd(exp[variavel][i++], 1);				//MENOS A LINHA DO J = 1;
			j = 1;
		}
		i = 0;
		while (str[i])
		{
			if (alpha_num(str[i]) == 1)
				i++;
			else
			{
				if (alpha_num(str[i]) == 0 && j == 0)
					ft_putchar_fd('$', 1);
				while (str[i])
				{
					ft_putchar_fd(str[i], 1);
					i++;
				}
			}
		}
		free(str);
	}
	return (0);
}

void	skips(char *argv, int j, char **exp)
{
	int	flag;
	int	i;
	int	quotes;

	flag = 0;
	i = 0;
	quotes = 0;
	while (argv[j])
	{
		if (argv[j] == '$' && quotes % 2 == 0)
		{
			echo_env(argv, j + 1, exp, 0);
			j++;
			while (argv[j] != '\0' && argv[j] != ' ' && argv[j] != '$'
				&& argv[j] != '"' && argv[j] != '\''/* && alpha_num(argv[j]) == 1*/)
				j++;
			if (argv[j] == '\'' || argv[j] == '"')
				i = 1;
		}
		else if (argv[j] == '"' && quotes % 2 == 0)
			flag++;
		else if (argv[j] == '\'' && flag % 2 == 0)
			quotes++;
		else
		{
			printf("\nentrou!\n");
			if (flag % 2 != 0 || quotes % 2 != 0)
			{
				ft_putchar_fd(argv[j], 1);
				if (argv[j] == '$')
					j++;
			}
			else
			{
				while (argv[j] && argv[j] == 32)
					j++;
				if (argv[j])
				{
					if (argv[j - 1] && argv[j - 1] == '$'
						&& alpha_num(argv[j]) == 0)
						ft_putchar_fd('$', 1);
					if (argv[j] == '$' && argv[j + 1] == '\'')
					{
						j = j;
					}
					else
					{
						ft_putchar_fd(argv[j], 1);
					}
					j++;
				}
			}
				
		}
		if (argv[j] && (argv[j] != '$' /*&& quotes % 2 == 0*/)) //se der merda testar, argv[j] || argv[j] != '$'
		{
			if (argv[j - 1] == '$' && argv[j] == '\'' && quotes % 2 != 0)
				ft_putchar_fd('$', 1);
			if (i == 0)
				j++;
			i = 0;
		}
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
