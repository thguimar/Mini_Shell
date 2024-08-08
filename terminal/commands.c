/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:12:32 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/21 20:41:26 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"

int	builtin_not_command(char **argv)
{
	if (ft_strcmp2("echo", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("cd", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("pwd", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("export", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("unset", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("exit", argv[0]) == 0)
		return (1);
	else if (ft_strcmp2("env", argv[0]) == 0)
		return (1);
	return (0);
}

void	path_comms(int argc, char **argv, char **env)
{
	char	**right_path;
	int		j;
	char	*test;

	j = -1;
	if (builtin_not_command(argv) == 1)
		exit (1);
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
