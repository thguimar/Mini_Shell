/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:53 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/27 15:58:34 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	(void)argv;
																			/*
																				LEMBRAR DE COLOCAR O RESULTADO
																				DE PWD NO EXPORT/ENV 
																			*/
	if (argc == 1)
		ft_putstr_fd(getcwd(argv[1], 100), 1);
	ft_putstr_fd("\n", 1);
}

