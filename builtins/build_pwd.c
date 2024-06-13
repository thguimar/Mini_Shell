/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:53 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/13 22:42:13 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

void	build_pwd(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		ft_putstr_fd(getcwd(argv[1], 100), 1);
	ft_putstr_fd("\n", 1);
}

/*
LEMBRAR DE COLOCAR O RESULTADO
DE PWD NO EXPORT/ENV
*/