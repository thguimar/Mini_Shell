/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:06:36 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/04 20:08:42 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include <stdio.h>

void	idk(char **builtins)
{
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
}

int	builtins(char *str)
{
	char	**builtins;
	int			i;

	builtins = ft_calloc(7, sizeof(char *));
	builtins[0] = ft_calloc(5, sizeof(char));
	builtins[1] = ft_calloc(3, sizeof(char));
	builtins[2] = ft_calloc(4, sizeof(char));
	builtins[3] = ft_calloc(7, sizeof(char));
	builtins[4] = ft_calloc(6, sizeof(char));
	builtins[5] = ft_calloc(4, sizeof(char));
	builtins[6] = ft_calloc(5, sizeof(char));	
	idk(builtins);
	i = 0;
	while (i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(builtins[i], str, ft_strlen(builtins[i])))
				return (i + 1);
		}
		i++;
	}
	return (0);
}
