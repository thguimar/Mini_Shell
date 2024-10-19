/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:16:39 by joana             #+#    #+#             */
/*   Updated: 2024/10/19 18:23:00 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	is_there_a_dollar(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i + 1] && str[i] == '$' && (ft_isalnum(str[i + 1]) == 1 \
		|| str[i + 1] == '$' || str[i + 1] == '?'))
			return (1);
		i++;
	}
	return (0);
}

void	expansions_helper(t_shell *utils, t_index *index)
{
	printf("...3\n");
	while (ft_isalnum((int)utils->expansions->split[index->i][index->k]) == 1)
		index->k++;
	utils->expansions->o_que_quiser = \
	ft_substr(utils->expansions->split[index->i], \
	index->j, index->k - index->j);
	while (utils->exp[index->l])
	{
		if (ft_strncmp(utils->expansions->o_que_quiser, utils->exp[index->l], \
		ft_strlen3(utils->exp[index->l])) == 0 \
		&& ft_strlen3(utils->expansions->o_que_quiser) \
		== ft_strlen3(utils->exp[index->l]))
			break ;
		index->l++;
	}
	if (utils->exp[index->l])
		expansions_value_found(utils, index);
	else
		expansions_value_not_found(utils, index);
}

void	expansions_bigger_helper(t_shell *utils, t_index *index)
{
	printf("...2\n");
	if (utils->expansions->split[index->i][index->j] == '$' \
	&& utils->expansions->split[index->i][index->j + 1] \
	&& (ft_isalnum(utils->expansions->split[index->i][index->j + 1]) == 1 \
	|| utils->expansions->split[index->i][index->j + 1] == '$' \
	|| utils->expansions->split[index->i][index->j + 1] == '?'))
	{
		index->j++;
		if (utils->expansions->split[index->i][index->j] == '$')
			expansions_dollar(utils, index);
		else
		{
			index->k = index->j;
			if (utils->expansions->split[index->i][index->k] == '?')
				expansions_exit_code(utils, index);
			else
				expansions_helper(utils, index);
		}
	}
	else
		index->j++;
	index->l = 0;
}

void	expansions_smaller_helper(t_index *index, t_shell *utils)
{
	index->j = 0;
	while (utils->expansions->split[index->i][index->j] \
	&& is_there_a_dollar(utils->expansions->split[index->i]) != 0)
	{
		while (utils->expansions->split[index->i][index->j] \
		&& utils->expansions->split[index->i][index->j] != '$')
			index->j++;
		index->x = index->j;
		expansions_bigger_helper(utils, index);
	}
}

char	*expansions(char *argv, t_shell *utils, int pa)
{
	t_index	index;

	index_initializer(&index);
	if (utils->expansions)
		free(utils->expansions);
	expansions_initializer(utils);
	utils->expansions->split = ft_split2(argv, ' ');
	if (pa == 2)
		return (free_dptr(utils->expansions->split, 0), ft_strdup(argv));
	while (utils->expansions->split && utils->expansions->split[++index.i])
	{
		if (pa == 0 && ft_strlen(utils->expansions->split[index.i]) == 1 \
		&& utils->expansions->split[index.i][0] == '$')
		{
			free(utils->expansions->split[index.i]);
			utils->expansions->split[index.i] = ft_calloc(sizeof(char), 1);
		}
		while (is_there_a_dollar(utils->expansions->split[index.i]) != 0)
			expansions_smaller_helper(&index, utils);
	}
	return (expansioner(utils, &index, NULL));
}
