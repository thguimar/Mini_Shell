/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:12:32 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/04 22:14:29 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"

void	path_comms(int argc, char **argv, char **env)
{
	char	**right_path;
	int		j;
	char	*test;

	j = -1;
	right_path = ft_split(PATH, ':');
	if (argc >= 1)
	{
		while (right_path[++j])
		{
			test = ft_strjoin(right_path[j], "/");
			test = ft_strjoin(test, argv[0]);
			if (access(test, F_OK) == 0)	//EXECVE's serao feito em child process, pois eles finalizam a execucao";
				execve(test, argv, env); //TROCAR ARGV+1 PELO COMANDO NA FUTURA STRUCT;
			free(test);
		}
	}
	j = -1;
	while(right_path[++j])
		free(right_path[j]);
	free(right_path);
}
