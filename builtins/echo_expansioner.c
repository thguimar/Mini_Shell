/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_expansioner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:38:35 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/09/03 17:03:01 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

bool	is_only_pipe(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (false);
	while (str[++i])
	{
		if (str[i] != '|')
			return (false);
	}
	return (true);
}

bool	is_there_pipe(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (false);
	while (str[++i])
	{
		if (str[i] == '|')
			return (true);
	}
	return (false);
}

int	size_before_pipe(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '|')
		i++;
	return (i);
}

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

/*char	**pipping_commands2(t_shell *utils, int x)
{
	int		j;
	int		i;
	int		ns;
	int		k;
	char	*tmp;
	char	*tmp2;
	char	**rtn;


	j = -1;
	i = 0;
	k = 0;
	rtn = ft_calloc(sizeof(char *), x + 1);
	while (utils->command[++j])
	{
		//printf(" this one here: %s\n", utils->command[j]);
		i = 0;
		//if (is_there_pipe(utils->command[j]) == false || utils->command[j][i] == '|')
		//{
		if (utils->command[j][i] != '\0' && utils->command[j][i] == '|')
		{
			while (utils->command[j][i] == '|')
				i++;
		}
		ns = size_before_pipe(utils->command[j + 1]);
		tmp = ft_substr(utils->command[j + 1], 0, ns);
		tmp2 = ft_strjoinn(utils->command[j] + i, tmp);
		if (utils->command[j][i] && is_there_pipe(utils->command[j + 1]) == false && is_there_pipe(utils->command[j]) == false)
			j++;
		//printf("AAAAAAAAAA: %s\n", tmp);
		free (tmp);
	//	printf("BBBBBBBBBB: %s\n========================\n", tmp2);
		if (rtn[k] && rtn[k][0])
			free(rtn[k]);
		rtn[k] = ft_strdup(tmp2);
		if (utils->command[j] && utils->command[j + 1] && utils->command[j + 1][0] != '|')
		{
			k++;
			//if (utils->command[j + 1][1] == '\0')
			if (is_there_pipe(utils->command[j + 1]) == true && utils->command[j + 1][ft_strlen(utils->command[j + 1])] != '|') 
				j++;
			free(tmp2);
		}
		if (is_there_pipe(utils->command[j + 1]) == true)
			k++;
		if (is_only_pipe(utils->command[j + 1]) == true)
			j++;
		//}
	}
	j = -1;
	while (rtn[++j])
		printf("CCCCCCCCCCC: %s\n", rtn[j]);
	return (rtn);
}*/


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

//int	quotes_verify(char *argv)
//{
//	int	sq;
//	int	dq;
//	int	j;
//
//	j = -1;
//	sq = 0;
//	dq = 0;
//	while (argv[++j])
//	{
//		if (argv[j] == '\'')
//			sq++;
//		else if (argv[j] == '"')
//			dq++;
//		if (sq == 2 || dq == 2)
//		{
//			if ((sq % 2 == 0 && dq % 2 != 0) || (sq % 2 != 0 && dq % 2 == 0))
//			{
//				write(1, "Incorrect opening of quotes\n", 28);
//				return (1);
//			}
//		}
//	}
//	if (sq % 2 != 0 || dq % 2 != 0)
//	{
//		write(1, "Incorrect opening of quotes\n", 28);
//		return (1);
//	}
//	return (0);
//}

//int	quotes_verify(char *argv)
//{
//	int	sq;
//	int	dq;
//	int	j;
//
//	j = 0;
//	sq = 0;
//	dq = 0;
//	while (argv[j])
//	{
//		if (argv[j] == '\'')
//			sq++;
//		else if (argv[j] == '"')
//			dq++;
//		j++;
//	}
//	if (dq % 2 != 0 || sq % 2 != 0)
//	{
//		write(1, "Odd number of quotes\n", 21);
//		return (1);
//	}
//	return (0);
//}

// array[0] -> sq1;
// array[1] -> sq2;
// array[2] -> dq1;
// array[3] -> dq2;

int	quotes_verify(char *argv)
{
	int	sq;
	int	dq;
	int	j;
	int	array[4];

	j = -1;
	sq = 0;
	dq = 0;
	array[0] = 0;
	array[1] = 0;
	array[2] = 0;
	array[3] = 0;
	while (argv[++j])
	{
		if (argv[j] == '\'' && sq % 2 == 0)
		{
			array[0] = j;
			sq++;
		}
		else if (argv[j] == '\'' && sq % 2 != 0)
		{
			array[1] = j;
			sq++;
		}
		else if (argv[j] == '"' && dq % 2 == 0)
		{
			array[2] = j;
			dq++;
		}
		else if (argv[j] == '"' && dq % 2 != 0)
		{
			array[3] = j;
			dq++;
		}
	}
	if (sq % 2 != 0 || dq % 2 != 0 || sq % 2 == 0 || dq % 2 == 0)
	{
		if ((dq % 2 == 0 && sq % 2 != 0) || (sq % 2 == 0 && dq % 2 != 0))
		{
			write(1, "Incorrect opening of quotes\n", 28);
			return (1);
		}
		else if (sq % 2 == 0 || dq % 2 == 0)
		{
			if ((array[0] > array[2] && array[1] < array[3]) || (array[2] > array[0] && array[3] < array[1]))
				return (0);
			else if ((array[0] > array[2] && array[0] < array[3]) || (array[2] > array[0] && array[2] < array[1]))
			{
				write(1, "Incorrect opening of quotes\n", 28);
				return (1);
			}
		}
	}
	return (0);
}

int	pipe_verify(char *argv)
{
	int	j;
	int	x;

	j = -1;
	if (argv && ft_strlen(argv) > 0)
	{
		while (argv[++j] || argv[j - 1] == '|')
		{
			if (j > 0 && argv[j - 1] && argv[j - 1] == '|')
				j--;
			x = 0;
			if (j == 0 && argv[j] == '|')
				return (ft_putendl_fd("wrong pipes", 1), -1);
			if (argv[j] == '|')
			{
				j++;
				while (argv[j] && argv[j] != '|')
				{
					if (argv[j] != ' ')
						x++;
					j++;
				}
				if (x == 0)
					return (ft_putendl_fd("wrong pipes", 1), -1);
			}
		}
	}
	return (0);
}