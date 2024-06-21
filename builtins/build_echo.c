/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/21 21:24:00 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

void	skips(char *argv, int j, t_shell *utils)
{
	int	flag;
	int yes;

	flag = 0;
	while (argv[j])
	{
		if (argv[j] == '$')
			break ;
		else if ((argv[j] == '"' || argv[j] == 39))
			flag++;
		else
		{
			if (flag % 2 != 0)
				ft_putchar_fd(argv[j], 1);
			else
			{
				while (argv[j + 1] && argv[j + 1] == 32)
					j++;
				if (argv[j])
					ft_putchar_fd(argv[j], 1);
			}
		}
		j++;
	}
	if (argv[j] == '$')
	{
		printf("TESTE\n");
		j = 0;
		//ERRO AQUI, O CMP DENTRO DA FUNCAO A BAIXO NAO ESTA SENDO FEITO BEM
		yes = var_equal_line2(utils->envr, argv);
		if (yes != -1)
		{
			while (utils->envr[yes][ft_strlen3(utils->envr[yes]) + j])
			{
				ft_putchar_fd(utils->envr[yes][ft_strlen3(utils->envr[yes]) + j], 1);
				j++;
			}
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

int	echo_func(char *argv, int flag, t_shell *utils)
{
	int	j;

	j = 0;
	if (j == 0 && echo_flag(argv) == 1)
	{
		flag = 1;
		j += flag_conut(argv);
	}	
	if (argv[j] != '\0')
		skips(argv, j, utils);
	return (flag);
}

void	build_echo(char *arr, t_shell *utils)
{
	int	flag;

	flag = 0;
	if (arr)
	{
		flag = echo_func(arr, flag, utils);
	}
	if (flag != 1)
		ft_putchar_fd('\n', 1);
}
