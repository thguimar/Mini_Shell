/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:03:27 by joanda-s          #+#    #+#             */
/*   Updated: 2024/10/17 17:41:39 by joana            ###   ########.fr       */
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

int	varlen(char *str, int k)
{
	while (str[k] && str[k] != '$')
		k++;
	return (k);
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
	//global_status()->status = 0;
}

void	expansions_value_found(t_shell *utils, t_index *index)
{
	printf("...6\n");
	utils->expansions->o_que_quiser2 = \
	ft_substr(utils->envr[index->l], \
	ft_strlen3(utils->expansions->o_que_quiser) + 1, \
	ft_strlen(utils->envr[index->l]) - \
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

char	*expansioner(t_shell *utils, t_index *index)
{
	char	*temp;

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
	free_dptr(utils->expansions->split, 0);
	return (utils->expansions->output);
}

void	expansions_helper(t_shell *utils, t_index *index)
{
	printf("...3\n");
	while (ft_isalnum((int)utils->expansions->split[index->i][index->k]) == 1)
		index->k++;
	utils->expansions->o_que_quiser = \
	ft_substr(utils->expansions->split[index->i], \
	index->j, index->k - index->j);
	while (utils->envr[index->l])
	{
		if (ft_strncmp(utils->expansions->o_que_quiser, utils->envr[index->l], \
		ft_strlen3(utils->envr[index->l])) == 0 \
		&& ft_strlen3(utils->expansions->o_que_quiser) \
		== ft_strlen3(utils->envr[index->l]))
			break ;
		index->l++;
	}
	if (utils->envr[index->l])
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
char	*expansions(char *argv, t_shell *utils, int pa)
{
	t_index	index;

	index.i = 0;
	index.j = 0;
	index.k = 0;
	index.l = 0;
	index.x = 0;
	if (utils->expansions)
		free(utils->expansions);
	expansions_initializer(utils);
	printf("...1\n");
	utils->expansions->split = ft_split2(argv, ' ');
	while (utils->expansions->split[index.i] != NULL)
		index.i++;
	index.i = 0;
	if (pa == 2)
	{
		printf("split[i] -> %s\n", utils->expansions->split[0]);
		printf("split[i] -> %s\n", utils->expansions->split[1]);
		printf("split[i] -> %s\n", utils->expansions->split[2]);
		printf("argv -> %s\n", argv);
		return (free_dptr(utils->expansions->split, 0), ft_strdup(argv));
	}
	while (utils->expansions->split && utils->expansions->split[index.i])
	{
		if (pa == 0 && ft_strlen(utils->expansions->split[index.i]) == 1 \
		&& utils->expansions->split[index.i][0] == '$')
		{
			free(utils->expansions->split[index.i]);
			utils->expansions->split[index.i] = ft_calloc(sizeof(char), 1);
		}
		printf("...11\n");
		while (is_there_a_dollar(utils->expansions->split[index.i]) != 0)
		{
			printf("...111\n");
			index.j = 0;
			while (utils->expansions->split[index.i][index.j] \
			&& is_there_a_dollar(utils->expansions->split[index.i]) != 0)
			{
				printf("...1111\n");
				while (utils->expansions->split[index.i][index.j] \
				&& utils->expansions->split[index.i][index.j] != '$')
					index.j++;
				index.x = index.j;
				expansions_bigger_helper(utils, &index);
			}
		}
		index.i++;
	}
	return (expansioner(utils, &index));
}

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
