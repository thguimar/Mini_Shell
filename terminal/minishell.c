/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:42:24 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/04 22:17:08 by thguimar         ###   ########.fr       */
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
		utils->exp = build_export(utils->j, command, env, utils->exp);
	else if (flag == 5)
		utils->envr = build_unset(utils->j, command, env);
	else if (flag == 6)
		build_env(utils->j, command, env);
	else if (flag == 7)
		build_exit();
}

int	main(int argc, char **argv, char **env)
{
	char 	*input;
	int		flag;
	char	**command;
	t_shell	*utils;

	utils = ft_calloc(2, sizeof(t_shell));
	utils->j = 0;
	utils->envr = env;
	if (argc != 1 || argv[1])
	{
		printf("invalid args (no args should be used)\n");
		exit (1);
	}
    while (1)
	{
    	input = readline("panic_shell> ");
		command = ft_split(input, ' ');
		while (command[utils->j])
			utils->j++;
		utils->process_id = fork();
		flag = (builtins(command[0]));
		if(utils->process_id == 0)
		{
			if (flag != 0)
				exec_builtin(flag, command, utils->envr, utils);
			else
				path_comms(utils->j, command, utils->envr);
		}
		waitpid(utils->process_id, NULL, 0);
    	if (input && *input)
    	    add_history(input);
    	free(input);
    }

    return 0;
}
