/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:42:24 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/12 15:10:45 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"

void	free_dptr(char **clc, int i)
{
	if (clc)
	{
		while (clc[i])
		{
			free(clc[i]);
			clc[i] = NULL;
			i++;
		}
		free(clc);
	}
}

void input_fixer(char *input)
{
	int	i;
	int	j;

	j = 0;
	i = 0;

	while (input[i] && input[i] == 32)
		i++;
	while (input[i] && input[i] != 32)
		i++;
	while (input[i] && input[i] == 32)
		i++;
	while (input[i])
	{
		input[j] = input[i];
		i++;
		j++;
	}
	input[j] = '\0';
}

void	exec_builtin(int flag, char **command, char **env, t_shell *utils)
{
	if (utils->input)
		input_fixer(utils->input);
	if (flag == 1)
		build_echo(utils->input, utils->exp);
	else if (flag == 2)
		build_cd(utils->j, command, env, utils);
	else if (flag == 3)
		build_pwd(utils->j, command);
	else if (flag == 4)
		utils->exp = build_export(utils->j, command, utils);
	else if (flag == 5)
		utils->exp = build_unset(utils->j, command, utils->exp, -1);
	else if (flag == 6)
		build_env(utils->j, command, utils);
	else if (flag == 7)
		build_exit(utils);
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

void	main2(t_shell *utils)
{
	int		flag;

	flag = 0;
	signal_search(ROOT);
	index_reset(utils);
	utils->input = readline("\x1b[5;95mpanic_shell> \x1b[0m");
	if (utils->input)
		add_history(utils->input);
	utils->command = ft_split(utils->input, ' ');
	while (utils->command[utils->j])
		utils->j++;
	//utils->process_id = fork();
	flag = builtins(utils->command[0], utils);
	if (flag == 0)
		path_comms(utils->j, utils->command, utils->envr, utils);
	//if (utils->process_id == 0)
	//	path_comms(utils->j, utils->command, utils->envr);
	if (flag != 0 && flag != 6)
		exec_builtin(flag, utils->command, utils->envr, utils);
	//waitpid(utils->process_id, NULL, 0);
	utils->j = 0;
	free_dptr(utils->command, 0);
	free(utils->input);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*utils;

	utils = ft_calloc(1, sizeof(t_shell));
	utils->export = ft_calloc(1, sizeof(t_builtvars));
	utils->j = 0;
	utils->envr = env;
	utils->exp = bubble_sort(0, env, 0, argc);
	if (argc != 1 || argv[1])
	{
		printf("invalid args (no args should be used)\n");
		exit (1);
	}
	while (1)
		main2(utils);
	return (0);
}
