/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:06:36 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/13 22:09:06 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include <stdio.h>

void	idk(t_stuff *stuff)
{
	stuff->builtins[0] = "echo";
	stuff->builtins[1] = "cd";
	stuff->builtins[2] = "pwd";
	stuff->builtins[3] = "export";
	stuff->builtins[4] = "unset";
	stuff->builtins[5] = "env";
	stuff->builtins[6] = "exit";
}

int	builtins_id(char *str, t_stuff *stuff)
{
	int	i;

	stuff->builtins = ft_calloc(7, sizeof(char *));
	stuff->builtins[0] = ft_calloc(5, sizeof(char));
	stuff->builtins[1] = ft_calloc(3, sizeof(char));
	stuff->builtins[2] = ft_calloc(4, sizeof(char));
	stuff->builtins[3] = ft_calloc(7, sizeof(char));
	stuff->builtins[4] = ft_calloc(6, sizeof(char));
	stuff->builtins[5] = ft_calloc(4, sizeof(char));
	stuff->builtins[6] = ft_calloc(5, sizeof(char));
	idk(stuff);
	i = 0;
	while (i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(stuff->builtins[i], str, \
			ft_strlen(stuff->builtins[i])))
				return (i + 1);
		}
		i++;
	}
	return (0);
}
