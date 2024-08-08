/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_expansioner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago-campus42 <thiago-campus42@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:38:35 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/07/24 16:37:48 by thiago-camp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

int	dollar_sign(char *str, int i)
{
	while (str[i] && str[i] != '$')
		i++;
	return (i);
}

char *expansion_var(char *argv, int j)
{
	int		i;
	char	*var;

	i = 0;
	while (argv[j] && alpha_num(argv[j]) == 1)
	{
		j++;
		i++;
	}	
	if (i == 0)
	{
		var = ft_calloc(dollar_sign(argv, j) + 2, sizeof(char));
		var[i] = '$';
		i++;
		while (argv[j] && argv[j] != '$')
		{
			var[i] = argv[j];
			j++;
			i++;
		}
		return (var);
	}
	i--;
	j--;
	var = ft_calloc(i + 1, sizeof(char));	
	while (i >= 0)
	{
		var[i] = argv[j];
		i--;
		j--;
	}
	return (var);
}

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

void	expansioner(char *argv, char **exp, int i)
{
	int		j;
	int		x;
	char	*str;
	int		variavel;
	char	*var;
	int		dollar;

	j = 0;
	x = 0;
	dollar = 0;
	str = ft_calloc(ft_strlen(argv) + 1, sizeof(char));
	while (argv[j])
	{
		if (argv[j] != '"')
		{
			if (argv[j] == '$')
			{
				var = expansion_var(argv, j + 1);
				variavel = var_equal_line_echo(exp, var);
				if (variavel != -1)
				{
					i = ft_strlen3(exp[variavel]) + 1;
					while (exp[variavel][i])
					{
						str[x] = exp[variavel][i];
						i++;
						x++;
					}
				}
				dollar = 1;
			}
			else
			{
				if (dollar == 1)
				{
					while (argv[j] && alpha_num(argv[j]) == 1)
						j++;
					dollar = 0;
				}
				if (x != 0)
				{
					if (x == 1 && argv[j - 1] == '$')
						ft_putchar_fd(argv[0], 1);
					str[x - 1] = argv[j];
				}
				else
					str[x] = argv[j];
			}
			x++;
		}
		j++;
	}
	ft_putstr_fd(str, 1);
	//free(var);
	free(str);
}

int quotes_verify(char c, char *argv, int j)
{
	int	x;

	x = 1;
	while (argv[j])
	{
		if (argv[j] == c)
			x++;
		j++;
	}
	return (x);
}

void	writter(char *argv)
{
	int		j;
	char	*str;
	int		x;

	j = 0;
	x = 0;
	str = ft_calloc(ft_strlen(argv) + 1, sizeof(char));
	while (argv[j])
	{
		if (argv[j] != '\'')
		{
			str[x] = argv[j];
			x++;
		}
		j++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

char	*quotes(char *argv, char **exp)
{
	int	j;
	int	flag;

	flag = 0;
	j = 0;
	while (argv[j])
	{
		if (argv[j] == '\'')
		{
			flag = 1;
			j++;
			if (quotes_verify('\'', argv, j) % 2 != 0)
				return (ft_putstr_fd("Odd Quotes", 1), NULL);
			break ;
		}
		else if (argv[j] == '"')
		{
			j++;
			if (quotes_verify('"', argv, j) % 2 != 0)
				return (ft_putstr_fd("Odd Quotes", 1), NULL);
			break ;
		}
		j++;
	}
	if (flag == 1)
		writter(argv);
	else
		expansioner(argv, exp, 0);
	return (NULL);
}
