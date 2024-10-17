/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:12:32 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/17 17:37:55 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	execute_comm(char **argv, char *test2, t_shell *utils, char *test)
{
	if (!test2 || access(test2, F_OK) == -1)
	{
		ft_putstr_fd("Command not found\n", 1);
		global_status()->status = 127;
		
	}
	else if (access(test2, F_OK) == 0)
	{
		if (access(test2, X_OK) != 0)
		{
			ft_putendl_fd("Permission denied", 1);
			global_status()->status = 126;
		}
		else
			execve(test2, argv, utils->exp);
	}
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

void	path_comms(char **argv, t_shell *utils, int i, int j)
{
	char	**right_path;
	char	*path;
	int		flag;
	char	*test;
	char	*test2;

	right_path = NULL;
	test = NULL;
	test2 = NULL;
	signal_search(IGNORE);
	utils->process_id = fork();
	if (utils->process_id == 0)
	{
		signal_search(CHILD);
		while (utils->exp[++i])
		{
			if (ft_strncmp(utils->exp[i], "PATH=", 5) == 0)
				path = ft_strdup(utils->exp[i]);
		}
		flag = 0;
		if (ft_strncmp(argv[0], "./", 2) == 0)
			test2 = ft_substr(argv[0], 2, ft_strlen(argv[0]) - 2);
		else
		{
			right_path = ft_split(path, ':');
			while (right_path[++j])
			{
				test = ft_strjoin(right_path[j], "/");
				test2 = ft_strjoin(test, argv[0]);
				if (access(test2, F_OK) == -1)
				{
					free(test);
					free(test2);
					test = NULL;
					test2 = NULL;
				}
				else if (access(test2, F_OK) == 0)
					break ;
			}
		}
		if (flag == 0)
			execute_comm(argv, test2, utils, test);
		free(path);
		free_dptr(right_path, 0);
		build_exit(argv, utils, 0, 0);
	}
	else
	{
		waitpid(utils->process_id, &global_status()->status, 0);
		status_handler(utils);
	}
	free(test);
	if (test2)
		free(test2);
	return ;
}
