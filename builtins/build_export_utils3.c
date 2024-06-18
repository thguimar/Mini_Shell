/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:34:30 by joana             #+#    #+#             */
/*   Updated: 2024/06/18 20:11:11 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	line_waste(t_builtvars *export, char **argv, int flag, int j)
{
	int	i;

	i = 0;
	free(export->mlc[export->m]);
	if (flag == 0)
		export->mlc[export->m] = \
		ft_calloc(ft_strlen(argv[export->j]) + 1, sizeof(char));
	if (flag == 1)
		export->mlc[export->i] = \
		ft_calloc(ft_strlen(argv[export->j]) + 1, sizeof(char));
	if (j >= 0)
	{
		while (argv[j][i++])
		{
			if (argv[j][i] == '=')
				flag = 1;
		}
	}
	return (flag);
}

int	is_there_equals(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '=')
			return (1);
		i++;
	}
	return (0);
}
