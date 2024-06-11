/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:42:24 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/11 20:25:37 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	exec_builtin(int flag, char **command, char **env, t_shell *utils)
{
	if (flag == 1)
		build_echo(command);
	else if (flag == 2)
		build_cd(utils->j, command, env);
	else if (flag == 3)
		build_pwd(utils->j, command);
	else if (flag == 4)
		utils->exp = build_export(utils->j, command, utils);//utils->exp
	else if (flag == 5)
		utils->envr = build_unset(utils->j, command, env);
	else if (flag == 6)
		build_env(utils->j, command, utils->envr);
	else if (flag == 7)
		build_exit();
}

void	index_reset(t_shell *utils)
{
	utils->j = 0;
	utils->export->i = 0;
	utils->export->j = 0;
	utils->export->k = 0;
	utils->export->l = 0;
	utils->export->m = 0;
	utils->export->n = 0;
	utils->export->x = 0;
	utils->export->flag = 0;
}

int	main(int argc, char **argv, char **env)
{
	char 	*input;
	int		flag;
	char	**command;
	t_shell	*utils;

	utils = ft_calloc(2, sizeof(t_shell));
	utils->export = ft_calloc(2, sizeof(t_builtvars));
	utils->j = 0;
	utils->envr = env;
	utils->exp = bubble_sort(0, env, 0);
	if (argc != 1 || argv[1])
	{
		printf("invalid args (no args should be used)\n");
		exit (1);
	}
    while (1)
	{
		index_reset(utils);
    	input = readline("\x1b[5;95mpanic_shell> \x1b[0m");
		command = ft_split(input, ' ');
		while (command[utils->j])
			utils->j++;
		utils->process_id = fork();
		flag = builtins(command[0]);
		if (utils->process_id == 0)
			path_comms(utils->j, command, env, flag);
		else if (flag != 0)
			exec_builtin(flag, command, utils->envr, utils);
		waitpid(utils->process_id, NULL, 0);
		utils->j = 0;
    	if (input && *input)
    	    add_history(input);
    	free(input);
    }

    return 0;
}
