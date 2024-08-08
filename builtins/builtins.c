/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:06:36 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/21 20:38:59 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include <stdio.h>

int	builtins(char *str, t_shell *utils)
{
	int			i;
	static int 	flag;

	if (utils->process_id == 0)
		return (0);
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
	i = 0;
	while (i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(utils->builtins[i], str, ft_strlen(utils->builtins[i])))
				return (i + 1);
		}
		i++;
	}
	return (0);
}
