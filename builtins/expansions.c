/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:03:27 by joanda-s          #+#    #+#             */
/*   Updated: 2024/10/19 18:23:46 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

char	*expansioner(t_shell *utils, t_index *index, char *temp)
{
	printf("...8\n");
	index->i = 0;
	while (utils->expansions->split[index->i])
	{
		if (index->i == 0)
		{
			utils->expansions->output = \
			ft_strjoinn(utils->expansions->split[index->i], \
			utils->expansions->split[index->i + 1]);
			if (utils->expansions->split[index->i + 1] == NULL)
				index->i += 1;
			else
				index->i += 2;
		}
		else
		{
			temp = ft_strdup(utils->expansions->output);
			free(utils->expansions->output);
			utils->expansions->output = ft_strjoinn(temp, \
			utils->expansions->split[index->i]);
			free(temp);
			index->i++;
		}
	}
	return (free_dptr(utils->expansions->split, 0), utils->expansions->output);
}
