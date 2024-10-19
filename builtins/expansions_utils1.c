/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:16:37 by joana             #+#    #+#             */
/*   Updated: 2024/10/19 18:24:00 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	in_between(char c, char *str, int i)
{
	int	x;

	x = 0;
	while (str[i + x] && str[i + x] != c)
		x++;
	return (x);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final;

	i = -1;
	j = -1;
	if (s1 != NULL && s2 != NULL)
		final = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 2);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	while (s1[++i] != '\0')
		final[i] = s1[i];
	final[i] = ' ';
	i++;
	while (s2[++j] != '\0')
		final[i++] = s2[j];
	final[i] = '\0';
	return (final);
}

int	pid_dollar(char *str, int j)
{
	int	x;

	if (j < 0)
		return (0);
	x = 0;
	while (j >= 0 && str[j] && str[j] == '$')
	{
		x++;
		j--;
	}
	return (x - 1);
}

void	expansions_initializer(t_shell *utils)
{
	utils->expansions = ft_calloc(1, sizeof(t_expansions));
	utils->expansions->dollar = 0;
	utils->expansions->o_que_quiser = NULL;
	utils->expansions->o_que_quiser2 = NULL;
	utils->expansions->o_que_quiser3 = NULL;
	utils->expansions->o_que_quiser4 = NULL;
	utils->expansions->o_que_quiser5 = NULL;
	utils->expansions->output = NULL;
	utils->expansions->pid_str = NULL;
	utils->expansions->split = NULL;
}

void	index_initializer(t_index *index)
{
	index->i = -1;
	index->j = 0;
	index->k = 0;
	index->l = 0;
	index->x = 0;
}
