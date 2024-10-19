/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:06:36 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/19 19:27:03 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	builtins(char *str, t_shell *utils, int i)
{
	static int	flag;

	if (flag == 0)
	{
		utils->builtins = ft_calloc(8, sizeof(char *));
		utils->builtins[0] = ft_strdup("echo");
		utils->builtins[1] = ft_strdup("cd");
		utils->builtins[2] = ft_strdup("pwd");
		utils->builtins[3] = ft_strdup("export");
		utils->builtins[4] = ft_strdup("unset");
		utils->builtins[5] = ft_strdup("env");
		utils->builtins[6] = ft_strdup("exit");
		flag = 1;
	}
	while (++i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(str, utils->builtins[i], ft_strlen(str) + 1))
				return (i + 1);
		}
	}
	return (0);
}
