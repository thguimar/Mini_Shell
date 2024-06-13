/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:12:32 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/13 18:16:42 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"

void	path_comms(int argc, char **argv, char **env, int flag)
{
	char	**right_path;
	int		j;
	char	*test;

	if (flag != 0)
		exit (1);
	j = -1;
	right_path = ft_split(PATH, ':');
	if (argc >= 1)
	{
		while (right_path[++j])
		{
			test = ft_strjoin(right_path[j], "/");
			test = ft_strjoin(test, argv[0]);
			if (access(test, F_OK) == 0)
				execve(test, argv, env);
			free(test);
		}
	}
	j = -1;
	while (right_path[++j])
		free(right_path[j]);
	free(right_path);
	exit (1);
}
//31: EXECVE's serao feito em child process, pois eles finalizam a execucao";
//32: TROCAR ARGV+1 PELO COMANDO NA FUTURA STRUCT;