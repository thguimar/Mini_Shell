/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd_utils3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:27:29 by joana             #+#    #+#             */
/*   Updated: 2024/10/16 16:28:39 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	change_env_and_export_dash_oldpwd_error(t_shell *utils, \
		char *str2, char *str)
{
	int	m;

	m = -1;
	while (utils->exp && utils->exp[++m])
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
	}
}

void	change_env_and_export_dash_oldpwd(t_shell *utils, char *str2, char *str)
{
	int	m;

	m = 1;
	while (utils->envr && utils->envr[++m])
	{
		if (ft_strncmp(utils->envr[m], "OLDPWD", 6) == 0)
		{
			str = ft_substr(utils->envr[m], 6, ft_strlen(utils->envr[m]) - 6);
			free(utils->envr[m]);
			utils->envr[m] = ft_strjoin("OLDPWD=", str2);
		}
	}
	change_env_and_export_dash_oldpwd_error(utils, str2, str);
	free(str2);
}

void	change_env_and_export_dash_pwd(t_shell *utils)
{
	int		m;
	char	*str;

	m = -1;
	str = getcwd(NULL, 0);
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

void	change_env_and_export_dash(t_shell *utils, char **argv, t_cd *cd)
{
	char	*str;
	char	*str2;

	str = NULL;
	str2 = getcwd(NULL, 0);
	(void) cd;
	chdir(argv[1]);
	change_env_and_export_dash_oldpwd(utils, str2, str);
	change_env_and_export_dash_pwd(utils);
}

void	get_cd(t_cd *cd, char **argv, t_shell *utils)
{
	cd->x = var_equal_line2(cd->utils->exp, "PWD=");
	cd->x = get_line_value(cd->utils->exp, cd->x);
	if (!argv[1] || argv[1][0] == '~')
		change_env_and_export_home(utils, -1);
	else if (argv[1] && argv[1][0] == '-')
		change_env_and_export_dash(utils, argv, cd);
	else if (argv[1])
		change_env_and_export_stuff(utils, argv, cd);
	cd->flag = 1;
}
