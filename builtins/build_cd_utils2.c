/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:24:08 by joana             #+#    #+#             */
/*   Updated: 2024/10/16 16:26:26 by joana            ###   ########.fr       */
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

void	change_env_and_export_home_oldpwd(t_shell *utils, char *str)
{
	int	m;

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

void	change_env_and_export_home_pwd(t_shell *utils)
{
	int		m;
	char	*str;

	str = getcwd(NULL, 0);
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

void	change_env_and_export_home_home(t_shell *utils)
{
	int		m;
	char	*str;

	m = -1;
	while (utils->envr && utils->envr[++m])
	{
		if (ft_strncmp(utils->envr[m], "HOME", 4) == 0)
		{
			str = ft_substr(utils->envr[m], 5, ft_strlen(utils->envr[m]) - 5);
			break ;
		}
	}
	m = -1;
	while (utils->exp && utils->exp[++m])
	{
		if (ft_strncmp(utils->envr[m], "HOME", 4) == 0)
		{
			str = ft_substr(utils->envr[m], 5, ft_strlen(utils->envr[m]) - 5);
			break ;
		}
	}
	free(str);
}

void	change_env_and_export_home(t_shell *utils, int m)
{
	char	*str;
	char	*new_cd;

	str = getcwd(NULL, 0);
	while (utils->envr && utils->envr[++m])
	{
		if (ft_strncmp(utils->envr[m], "HOME", 4) == 0)
		{
			new_cd = ft_substr(utils->envr[m], 5, \
			ft_strlen(utils->envr[m]) - 5);
			if (chdir(new_cd) == -1)
			{
				free(new_cd);
				free(str);
				ft_putendl_fd("File or directory not found", 1);
				global_status()->status = 1;
				return ;
			}
		}
	}
	change_env_and_export_home_oldpwd(utils, str);
	change_env_and_export_home_pwd(utils);
	change_env_and_export_home_home(utils);
	free(str);
}
