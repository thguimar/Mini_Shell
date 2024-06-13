/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:03:58 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/13 19:36:18 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	argc_2(t_cd *cd, char **argv)
{
	cd->i = 0;
	cd->j = 1;
	if (chdir(argv[1]) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", 1);
		ft_putstr_fd(argv[1], 1);
		ft_putstr_fd("\n", 1);
	}
	else if (is_twopoints(argv[1]) == 0)
	{
		if (argv[1][cd->i] == '/')
			cd->str = ft_calloc(ft_strlen(argv[1]) + 1, sizeof(char));
		else
		{
			cd->str = ft_calloc(ft_strlen(argv[1]) + 2, sizeof(char));
			cd->str[0] = '/';
		}
		while (argv[1][cd->i])
			cd->str[cd->j++] = argv[1][cd->i++];
		chdir(getcwd(argv[1], 100));
		cd->flag = 1;
	}
}

void	argc_1(t_cd *cd, char *home, int argc, char **argv)
{
	cd->i = 0;
	while (argc == 1 || (argv[1][cd->i] == 47 && argv[1][cd->i]))
	{
		cd->i++;
		if (argc == 1)
		{
			chdir(home);
			break ;
		}
		if (argv[1][cd->i] == '\0')
		{
			chdir("/");
			break ;
		}
	}
}
