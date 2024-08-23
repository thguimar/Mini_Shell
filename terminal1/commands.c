/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:12:32 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/23 21:13:53 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libs/builtins.h"

void	execute_comm(char **argv, char *test2, char **env, char *test)
{
	if (access(test2, F_OK) == 0)
		execve(test2, argv, env);
	free(test);
	free(test2);
}

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

void	path_comms(int argc, char **argv, char **env, t_shell *utils)
{
	char	**right_path;
	int		j;
	char	*test;
	char	*test2;

	j = -1;
	utils->process_id = fork();
	if (utils->process_id == 0)
	{
		signal_search(CHILD);
		right_path = ft_split(PATH, ':');
		if (argc >= 1)
		{
			while (right_path[++j])
			{
				test = ft_strjoin(right_path[j], "/");
				test2 = ft_strjoin(test, argv[0]);
				execute_comm(argv, test2, env, test);
			}
		}
		free_dptr(right_path, 0);
		build_exit(utils);
	}
	else
		waitpid(utils->process_id, NULL, 0);
	return ;
}
