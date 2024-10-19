/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:20:17 by joana             #+#    #+#             */
/*   Updated: 2024/10/19 18:24:04 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	expansions_dollar(t_shell *utils, t_index *index)
{
	printf("...4\n");
	utils->expansions->dollar = pid_dollar(utils->expansions->split[index->i], \
	index->j);
	if (utils->expansions->dollar % 2 != 0)
		utils->expansions->pid_str = ft_getpid();
	index->j++;
	utils->expansions->o_que_quiser = \
	ft_substr(utils->expansions->split[index->i], 0, index->j - 2);
	utils->expansions->o_que_quiser2 = \
	ft_substr(utils->expansions->split[index->i], index->j, \
	ft_strlen(utils->expansions->split[index->i]) - index->j);
	free(utils->expansions->split[index->i]);
	utils->expansions->o_que_quiser3 = \
	ft_strjoin(utils->expansions->o_que_quiser, utils->expansions->pid_str);
	free(utils->expansions->o_que_quiser);
	utils->expansions->split[index->i] = \
	ft_strjoin(utils->expansions->o_que_quiser3, \
	utils->expansions->o_que_quiser2);
	free(utils->expansions->o_que_quiser2);
	free(utils->expansions->o_que_quiser3);
	free(utils->expansions->pid_str);
}

void	expansions_exit_code(t_shell *utils, t_index *index)
{
	printf("...5\n");
	utils->expansions->o_que_quiser = \
	ft_substr(utils->expansions->split[index->i], \
	index->k + 1, ft_strlen(utils->expansions->split[index->i]) - index->k);
	free(utils->expansions->split[index->i]);
	printf("global status to print -> %d\n", global_status()->status);
	utils->expansions->o_que_quiser2 = ft_itoa(global_status()->status);
	utils->expansions->split[index->i] = \
	ft_strjoin(utils->expansions->o_que_quiser2, \
	utils->expansions->o_que_quiser);
	free(utils->expansions->o_que_quiser);
	free(utils->expansions->o_que_quiser2);
	global_status()->status = 0;
}

void	expansions_value_found_helper(t_shell *utils, t_index *index)
{
	utils->expansions->o_que_quiser2 = \
	ft_strjoin(utils->expansions->o_que_quiser5, \
	utils->expansions->o_que_quiser4);
	free(utils->expansions->o_que_quiser4);
	free(utils->expansions->o_que_quiser5);
	free(utils->expansions->split[index->i]);
	utils->expansions->split[index->i] = \
	ft_strdup(utils->expansions->o_que_quiser2);
	free(utils->expansions->o_que_quiser2);
}

void	expansions_value_found(t_shell *utils, t_index *index)
{
	printf("...6\n");
	utils->expansions->o_que_quiser2 = \
	ft_substr(utils->exp[index->l], \
	ft_strlen3(utils->expansions->o_que_quiser) + 1, \
	ft_strlen(utils->exp[index->l]) - \
	ft_strlen(utils->expansions->o_que_quiser) - 1);
	free(utils->expansions->o_que_quiser);
	if (index->x != 0)
		utils->expansions->o_que_quiser3 = \
		ft_substr(utils->expansions->split[index->i], 0, index->x);
	else
		utils->expansions->o_que_quiser3 = NULL;
	while (utils->expansions->split[index->i][index->j])
		index->j++;
	utils->expansions->o_que_quiser4 = \
	ft_substr(utils->expansions->split[index->i], \
	index->k, index->j - index->k);
	utils->expansions->o_que_quiser5 = \
	ft_strjoin(utils->expansions->o_que_quiser3, \
	utils->expansions->o_que_quiser2);
	free(utils->expansions->o_que_quiser2);
	free(utils->expansions->o_que_quiser3);
	expansions_value_found_helper(utils, index);
}

void	expansions_value_not_found(t_shell *utils, t_index *index)
{
	printf("...7\n");
	utils->expansions->o_que_quiser2 = \
	ft_substr(utils->expansions->split[index->i], 0, index->j - 1);
	utils->expansions->o_que_quiser3 = \
	ft_substr(utils->expansions->split[index->i], index->k, \
	ft_strlen(utils->expansions->split[index->i]) - index->k);
	free(utils->expansions->split[index->i]);
	utils->expansions->split[index->i] = \
	ft_strjoinn(utils->expansions->o_que_quiser2, \
	utils->expansions->o_que_quiser3);
	free(utils->expansions->o_que_quiser);
	free(utils->expansions->o_que_quiser2);
	free(utils->expansions->o_que_quiser3);
}
