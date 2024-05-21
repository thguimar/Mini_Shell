/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/21 15:20:36 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
//#include "mini_shell.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	int	j;

	if (argc != 1)
	{
		j = 1;
		while (argv[j])
		{
			ft_putstr_fd(argv[j], 1);
			if (argv[j + 1] != NULL)
				ft_putchar_fd(' ', 1);
			else
				break ;
			j++;
		}
	}
	ft_putchar_fd('\n', 1);
}
