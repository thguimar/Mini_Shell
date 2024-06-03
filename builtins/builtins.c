/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:06:36 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/29 17:11:51 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include <stdio.h>

int	*build_array(char *str)
{
	static void	*builtins[7][2] = {
	{"echo", "build_echo"},
	{"cd", "build_cd"},
	{"pwd", "build_pwd"},
	{"export", "build_export"},
	{"unset", "build_unset"},
	{"env", "build_env"},
	{"exit", "build_exit"}
	};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(builtins[i][0], str, ft_strlen(builtins[i][0])))
				return (builtins[i][1]);
		}
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("%s", (char *)build_array(argv[1]));
}
