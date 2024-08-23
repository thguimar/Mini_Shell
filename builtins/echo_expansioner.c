/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_expansioner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:38:35 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/23 03:09:21 by joanda-s         ###   ########.fr       */
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

char	**pipping_commands2(t_shell *utils, int x)
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
		/*if (is_there_pipe(utils->command[j]) == false || utils->command[j][i] == '|')
		{*/
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
}

char	**pipping_commands(t_shell *utils)
{
	int		i;
	int		j;
	int		x;
	bool	pipe;
	char	**rtn;

	i = -1;
	x =  1;
	j = -1;
	pipe = false;
	while (utils->command[++j])
	{
		while (utils->command[j][++i])
		{
			if (utils->command[j][i] == '|')
			{
				pipe = true;
				x++;
			}
		}
		i = -1;
	}
	if (pipe == true)
	{
		rtn = pipping_commands2(utils, x);
		return (rtn);
	}
	else
		return (utils->command);
}

int	quotes_verify(char *argv)
{
	int	sq;
	int	dq;
	int	j;

	j = 0;
	sq = 0;
	dq = 0;
	while (argv[j])
	{
		if (argv[j] == '\'')
			sq++;
		else if (argv[j] == '"')
			dq++;
		j++;
	}
	if (dq % 2 != 0 || sq % 2 != 0)
	{
		write(1, "Odd number of quotes\n", 21);
		return (1);
	}
	return (0);
}

int	pipe_verify(char **argv)
{
	int	p;
	int	j;

	j = -1;
	p = 0;
	while (argv[++j])
	{
		if (j == 0 && argv[j][0] == '|')
			return (ft_putendl_fd("wrong pipes", 1), -1);
		else if (argv[j][ft_strlen(argv[j]) - 1] == '|')
			p = 1;
		else
			p = 0;
	}
	if (p == 1)
		return (ft_putendl_fd("wrong pipes", 1), -1);
	return (0);
}
