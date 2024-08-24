/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:12:32 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/24 19:35:37 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	execute_comm(char **argv, char *test2, t_shell *utils, char *test)
{
	//int		i;
	//int		n;
	//char	*num;

	//i = 0;
	/*if (ft_strncmp(test2, "minishell", 9) == 0)
	{
		while (ft_strncmp("SHLVL", utils->exp[i], \
				ft_strlen3(utils->exp[i])) != 0)
			i++;
		if (utils->exp[i] != NULL)
		{
			n = ft_atoi(utils->exp[i] + ft_strlen3(utils->exp[i]) + 1);
			n++;
			free (utils->exp[i]);
			num = ft_itoa(n);
			utils->exp[i] = ft_strjoin("SHLVL=", num);
			free (num);
		}
		else
			utils->exp[i] = ft_strdup("SHLVL=1");
	}*/
	if (access(test2, F_OK) == 0)
		execve(test2, argv, utils->exp);
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

void	path_comms(char **argv, t_shell *utils)
{
	char	**right_path;
	int		j;
	int		flag;
	char	*test;
	char	*test2;

	j = -1;
	right_path = NULL;
	test = NULL;
	utils->process_id = fork();
	signal_search(CHILD);
	if (utils->process_id == 0)
	{
		signal_search(CHILD);
		flag = 0;
		if (ft_strncmp(argv[0], "./", 2) == 0)
			test2 = ft_substr(argv[0], 2, ft_strlen(argv[0]) - 2);
		else
		{
			right_path = ft_split(PATH, ':');
			while (right_path[++j])
			{
				test = ft_strjoin(right_path[j], "/");
				test2 = ft_strjoin(test, argv[0]);
				execute_comm(argv, test2, utils, test);
				flag = 1;
			}
		}
		if (flag == 0)
			execute_comm(argv, test2, utils, test);
		free_dptr(right_path, 0);
		build_exit(argv, utils);
	}
	else
		waitpid(utils->process_id, NULL, 0);
	return ;
}
