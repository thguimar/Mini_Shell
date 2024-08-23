/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:03:58 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/23 16:17:48 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	get_line_value(char **exp, int line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = ft_strlen3(exp[line]);
	while (exp[line][++i])
		j++;
	return (j);
}

void	get_cd(t_cd *cd, char **argv)
{
	cd->x = var_equal_line2(cd->utils->exp, "PWD=");
	cd->x = get_line_value(cd->utils->exp, cd->x);
	chdir(getcwd(argv[1], cd->x + ft_strlen(argv[1])));
	cd->flag = 1;
}

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
		{
			cd->str = ft_calloc(ft_strlen(argv[1]) + 1, sizeof(char));
			cd->str[cd->j - 1] = argv[1][cd->i];
			cd->i++;
		}
		else
		{
			cd->str = ft_calloc(ft_strlen(argv[1]) + 1, sizeof(char));
			cd->str[0] = '/';
		}
		while (argv[1][cd->i])
			cd->str[cd->j++] = argv[1][cd->i++];
		get_cd(cd, argv);
	}
}

void	argc_1(t_cd *cd, char *home, int argc, char **argv)
{
	int	j;

	j = 0;
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
