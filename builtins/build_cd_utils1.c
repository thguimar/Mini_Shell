/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:03:58 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/19 20:22:32 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	change_env_and_export_stuff_oldpwd(t_shell *utils, char *str)
{
	int	m;

	printf("str oldpwd -> %s\n", str);
	m = -1;
	while (utils->envr && utils->envr[++m])
	{
		if (ft_strncmp(utils->envr[m], "OLDPWD", 6) == 0)
		{
			free(utils->envr[m]);
			utils->envr[m] = ft_strjoin("OLDPWD=", str);
		}
	}
	m = -1;
	while (utils->exp && utils->exp[++m])
	{
		if (ft_strncmp(utils->exp[m], "OLDPWD", 6) == 0)
		{
			free(utils->exp[m]);
			utils->exp[m] = ft_strjoin("OLDPWD=", str);
		}
	}
}

void	change_env_and_export_stuff_pwd(t_shell *utils)
{
	int		m;
	char	*str;

	str = getcwd(NULL, 0);
	printf("str pwd -> %s\n", str);
	m = -1;
	while (utils->envr && utils->envr[++m])
	{
		if (ft_strncmp(utils->envr[m], "PWD", 3) == 0)
		{
			free(utils->envr[m]);
			utils->envr[m] = ft_strjoin("PWD=", str);
		}
	}
	m = -1;
	while (utils->exp && utils->exp[++m])
	{
		if (ft_strncmp(utils->exp[m], "PWD", 3) == 0)
		{
			free(utils->exp[m]);
			utils->exp[m] = ft_strjoin("PWD=", str);
		}
	}
	free(str);
}

void	change_env_and_export_stuff(t_shell *utils, char **argv, t_cd *cd)
{
	char	*str;

	(void)cd;
	str = getcwd(NULL, 0);
	if (chdir(argv[1]) == -1)
	{
		free(str);
		ft_putendl_fd("File or directory not found", 1);
		global_status()->status = 1;
		return ;
	}
	change_env_and_export_stuff_oldpwd(utils, str);
	change_env_and_export_stuff_pwd(utils);
	free(str);
}

//quando fazes cd alguma coisa (inclui dois pontos), quero usar a funcao do 
//getcwd (nao aqui) e usar o output como old pwd (no env e no export)

//quero trocar de diretorio (chdir), fazer exatamente o mesmo 
//passo acima mas troco o PWD em vez do old pwd

//caso especifico sem nada, o meu old pwd passa a ser o 
//output do cwd e o pwd passa a ser o home

//talvez implementar o cd ~ e o cd -
//cd ~ vai fazer a mesma coisa q o cd sem nada
//cd -, basta trocar o old pwd com o pwd (isto depois de trocar para algum lado)

void	argc_2(t_cd *cd, char **argv, t_shell *utils)
{
	cd->i = 0;
	cd->j = 1;
	get_cd(cd, argv, utils);
}
