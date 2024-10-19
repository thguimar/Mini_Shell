/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_expansioner_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:18:22 by joana             #+#    #+#             */
/*   Updated: 2024/10/19 18:19:18 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

t_pipe_comms	*new_pipe_node(void)
{
	t_pipe_comms	*next0;

	next0 = ft_calloc(1, sizeof(t_pipe_comms));
	if (!next0)
		return (NULL);
	next0->fd_in = NULL;
	next0->fd_out = NULL;
	next0->strp = NULL;
	next0->args = NULL;
	next0->next = NULL;
	return (next0);
}

void	new_pipe_back(t_pipe_comms **pcomms, t_pipe_comms *new_pipe)
{
	t_pipe_comms	*next1;

	next1 = *pcomms;
	if (next1)
	{
		if (*pcomms == NULL)
			*pcomms = new_pipe;
		else
		{
			while (next1->next)
				next1 = next1->next;
		}
		next1->next = new_pipe;
	}
}

char	**pipping_commands2(char *str, int x, t_pipe_comms *pcomms)
{
	char			**rtn;
	t_pipe_comms	*copy;
	int				i;
	int				j;

	j = 0;
	i = -1;
	if (x > 1)
	{
		while (++j < x)
		{
			copy = new_pipe_node();
			new_pipe_back(&pcomms, copy);
		}
	}
	copy = pcomms;
	rtn = ft_calloc(sizeof(char *), x + 1);
	rtn = ft_split(str, '|');
	while (rtn[++i])
	{
		copy->strp = rtn[i];
		copy = copy->next;
	}
	return (rtn);
}

char	**pipping_commands(char *input, t_pipe_comms *pcomms)
{
	int		i;
	int		x;
	char	**rtn;

	i = -1;
	x = 1;
	while (input[++i])
	{
		if (input[i] == '|')
			x++;
	}
	rtn = pipping_commands2(input, x, pcomms);
	return (rtn);
}
