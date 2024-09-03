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

void	change_env_and_export_stuff(t_shell *utils, char **argv, t_cd *cd)
{
	char	*str;
	int		m;

	(void)cd;
	str = getcwd(NULL, 0);
	if (chdir(argv[1]) == -1)
	{
		free(str);
		ft_putendl_fd("File or directory not found", 1);
		global_status()->status = 1;
		return ;
	}
	m = 0;
	while (utils->envr && utils->envr[m])
	{
		if (ft_strncmp(utils->envr[m], "OLDPWD", 6) == 0)
		{
			free(utils->envr[m]);
			utils->envr[m] = ft_strjoin("OLDPWD=", str);
		}
		m++;
	}
	m = 0;
	while (utils->exp && utils->exp[m])
	{
		if (ft_strncmp(utils->exp[m], "OLDPWD", 6) == 0)
		{
			free(utils->exp[m]);
			utils->exp[m] = ft_strjoin("OLDPWD=", str);
		}
		m++;
	}
	free(str);
	m = 0;
	//chdir(getcwd(argv[1], cd->x + ft_strlen(argv[1])));
	str = getcwd(NULL, 0);
	while (utils->envr && utils->envr[m])
	{
		if (ft_strncmp(utils->envr[m], "PWD", 3) == 0)
		{
			free(utils->envr[m]);
			utils->envr[m] = ft_strjoin("PWD=", str);
		}
		m++;
	}
	m = 0;
	while (utils->exp && utils->exp[m])
	{
		if (ft_strncmp(utils->exp[m], "PWD", 3) == 0)
		{
			free(utils->exp[m]);
			utils->exp[m] = ft_strjoin("PWD=", str);
		}
		m++;
	}
	free(str);
}

void	change_env_and_export_home(t_shell *utils, char **argv, t_cd *cd)
{
	char	*str;
	char	*new_cd;
	int		m;

	(void)argv;
	str = getcwd(NULL, 0);
	m = 0;
	(void) cd;
	//chdir(argv[1]);
	//chdir(getcwd(argv[1], cd->x + ft_strlen(argv[1])));
	while (utils->envr && utils->envr[m])
	{
		if (ft_strncmp(utils->envr[m], "HOME", 4) == 0)
		{
			new_cd = ft_substr(utils->envr[m], 5, ft_strlen(utils->envr[m]) - 5);
			if (chdir(new_cd) == -1)
			{
				free(new_cd);
				free(str);
				ft_putendl_fd("File or directory not found", 1);
				global_status()->status = 1;
				return ;
			}
		}
		m++;
	}
	m = 0;
	while (utils->envr && utils->envr[m])
	{
		if (ft_strncmp(utils->envr[m], "OLDPWD", 6) == 0)
		{
			free(utils->envr[m]);
			utils->envr[m] = ft_strjoin("OLDPWD=", str);
		}
		m++;
	}
	m = 0;
	while (utils->exp && utils->exp[m])
	{
		if (ft_strncmp(utils->exp[m], "OLDPWD", 6) == 0)
		{
			free(utils->exp[m]);
			utils->exp[m] = ft_strjoin("OLDPWD=", str);
		}
		m++;
	}
	free(str);
	m = 0;
	while (utils->envr && utils->envr[m])
	{
		if (ft_strncmp(utils->envr[m], "HOME", 4) == 0)
		{
			str = ft_substr(utils->envr[m], 5, ft_strlen(utils->envr[m]) - 5);
			break ;
		}
		m++;
	}
	m = 0;
	while (utils->exp && utils->exp[m])
	{
		if (ft_strncmp(utils->envr[m], "HOME", 4) == 0)
		{
			str = ft_substr(utils->envr[m], 5, ft_strlen(utils->envr[m]) - 5);
			break ;
		}
		m++;
	}
	m = 0;
	while (utils->envr && utils->envr[m])
	{
		if (ft_strncmp(utils->envr[m], "PWD", 3) == 0)
		{
			free(utils->envr[m]);
			utils->envr[m] = ft_strjoin("PWD=", str);
		}
		m++;
	}
	m = 0;
	while (utils->exp && utils->exp[m])
	{
		if (ft_strncmp(utils->exp[m], "PWD", 3) == 0)
		{
			free(utils->exp[m]);
			utils->exp[m] = ft_strjoin("PWD=", str);
		}
		m++;
	}
	free(str);
}

void	change_env_and_export_dash(t_shell *utils, char **argv, t_cd *cd)
{
	int		m;
	char	*str;
	char	*str2;

	m = 0;
	str2 = getcwd(NULL, 0);
	(void) cd;
	chdir(argv[1]);
	//chdir(getcwd(argv[1], cd->x + ft_strlen(argv[1])));
	while (utils->envr && utils->envr[m])
	{
		if (ft_strncmp(utils->envr[m], "OLDPWD", 6) == 0)
		{
			str = ft_substr(utils->envr[m], 6, ft_strlen(utils->envr[m]) - 6);
			free(utils->envr[m]);
			utils->envr[m] = ft_strjoin("OLDPWD=", str2);
		}
		m++;
	}
	m = 0;
	while (utils->exp && utils->exp[m])
	{
		if (ft_strncmp(utils->exp[m], "OLDPWD", 6) == 0)
		{
			str = ft_substr(utils->exp[m], 7, ft_strlen(utils->exp[m]) - 7);
			if (chdir(str) == -1)
			{
				free(str2);
				free(str);
				ft_putendl_fd("File or directory not found", 1);
				global_status()->status = 1;
				return ;
			}
			free(utils->exp[m]);
			utils->exp[m] = ft_strjoin("OLDPWD=", str2);
		}
		m++;
	}
	free(str2);
	m = 0;
	while (utils->envr && utils->envr[m])
	{
		if (ft_strncmp(utils->envr[m], "PWD", 3) == 0)
		{
			free(utils->envr[m]);
			utils->envr[m] = ft_strjoin("PWD=", str);
		}
		m++;
	}
	m = 0;
	while (utils->exp && utils->exp[m])
	{
		if (ft_strncmp(utils->exp[m], "PWD", 3) == 0)
		{
			free(utils->exp[m]);
			utils->exp[m] = ft_strjoin("PWD=", str);
		}
		m++;
	}
	free(str);
}
//quando fazes cd alguma coisa (inclui dois pontos), quero usar a funcao do getcwd (nao aqui) e usar o output como old pwd (no env e no export)
//quero trocar de diretorio (chdir), fazer exatamente o mesmo passo acima mas troco o PWD em vez do old pwd
//caso especifico sem nada, o meu old pwd passa a ser o output do cwd e o pwd passa a ser o home
//talvez implementar o cd ~ e o cd -
//cd ~ vai fazer a mesma coisa q o cd sem nada
//cd -, basta trocar o old pwd com o pwd (isto depois de trocar para algum lado)

void	get_cd(t_cd *cd, char **argv, t_shell *utils)
{
	cd->x = var_equal_line2(cd->utils->exp, "PWD=");
	cd->x = get_line_value(cd->utils->exp, cd->x);
	if (!argv[1] || argv[1][0] == '~')
		change_env_and_export_home(utils, argv, cd);
	else if (argv[1] && argv[1][0] == '-')
		change_env_and_export_dash(utils, argv, cd);
	else if (argv[1])
		change_env_and_export_stuff(utils, argv, cd);
	cd->flag = 1;
}

void	argc_2(t_cd *cd, char **argv, t_shell *utils)
{
	cd->i = 0;
	cd->j = 1;
	//if (chdir(argv[1]) == -1)
	//{
	//	ft_putstr_fd("cd: no such file or directory: ", 1);
	//	ft_putstr_fd(argv[1], 1);
	//	ft_putstr_fd("\n", 1);
	//}
	//else if (is_twopoints(argv[1]) == 0)
	//{
	//	if (argv[1][cd->i] == '/')
	//	{
	//		cd->str = ft_calloc(ft_strlen(argv[1]) + 1, sizeof(char));
	//		cd->str[cd->j - 1] = argv[1][cd->i];
	//		cd->i++;
	//	}
	//	else
	//	{
	//		cd->str = ft_calloc(ft_strlen(argv[1]) + 1, sizeof(char));
	//		cd->str[0] = '/';
	//	}
	//	while (argv[1][cd->i])
	//		cd->str[cd->j++] = argv[1][cd->i++];
	//}
	get_cd(cd, argv, utils);
}

void	argc_1(t_cd *cd, char *home, int argc, char **argv)
{
	//int	j;

	//j = 0;
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
