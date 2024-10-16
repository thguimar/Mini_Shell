/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:42:24 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/16 19:39:46 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	input_fixer(char *input)
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
		build_echo(utils->input, utils, 0, -1);
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
		build_exit(command, utils, 1, 0);
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

char	***scary_thing(char	**dptr)
{
	char	***rtn;
	int		j;
	int		x;

	j = 0;
	x = 0;
	while (dptr[j])
		j++;
	rtn	= ft_calloc(sizeof(char **), j + 1);
	j = -1;
	while (dptr[++j])
	{
		rtn[x] = ft_split(dptr[j], ' ');
		x++;
	}
	x = 0;
	while (rtn[x])
	{
		j = 0;
		while (rtn[x][j])
			j++;
		x++;
	}
	return (rtn);
}

int	main2(t_shell *utils, int flag)
{
	//int				x;
	t_pipe_comms	*pcomms;

	pcomms = ft_calloc(1, sizeof(t_pipe_comms));
	//x = -1;
	//free_tptr(utils->bizarre, 0);
	free_dptr(utils->command, 0);
	//signal_search(IGNORE); //ele funciona aqui, e tem mais sentido estar aqui, mas não me apetece estragar as perfeitas 25 linhas da função
	signal_search(ROOT);
	index_reset(utils);
	utils->input = readline("\x1b[5;95mpanic_shell> \x1b[0m");
	//utils->input = readline("minishell"); //prompt escreve por cima por causa do prompt ser interativo
	if (utils->input)
		add_history(utils->input);
	else
		return (free_dptr(utils->envr, 0), free(utils->export), free_dptr(utils->exp, 0), free(utils), 0);
	if (quotes_verify(utils->input, 0, 0, 0) == 0)
	{
		if (pipe_verify(utils->input, -1, 0) == 0)
		{
			utils->command = pipping_commands(utils->input, pcomms);
			while (pcomms != NULL)
				pcomms = pcomms->next;
			//utils->bizarre = scary_thing(utils->command);
			//while(utils->bizarre[++x])
			//{
			utils->command = ft_split(utils->command[0], ' ');
			while (utils->command[utils->j])
				utils->j++;
			//has_quotes(utils->lala[2], 0, utils->input, utils->lala[0]);
			flag = builtins(utils->command[0], utils, -1);
			if (flag == 0)
				path_comms(utils->command, utils, -1, -1);
			if (flag != 0)
				exec_builtin(flag, utils->command, utils->envr, utils);
			utils->j = 0;
			free_dptr(utils->command, 0);
			//}
			//free_tptr(utils->bizarre, 0);
		}
		//utils->bizarre = NULL;
		utils->command = NULL;
	}
	//if (utils->command)
	//	free_dptr(utils->command, 0);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	*utils;
	int		i;
	int		n;
	char	*num;

	i = 0;
	utils = ft_calloc(1, sizeof(t_shell));
	utils->export = ft_calloc(1, sizeof(t_builtvars));
	utils->j = 0;
	utils->envr = dptr_dup(env);
	while (utils->envr[i] && ft_strncmp("SHLVL", utils->envr[i], \
			ft_strlen3(utils->envr[i])) != 0)
		i++;
	if (utils->envr[i] != NULL)
	{
		n = ft_atoi(utils->envr[i] + ft_strlen3(utils->envr[i]) + 1);
		n++;
		free (utils->envr[i]);
		num = ft_itoa(n);
		utils->envr[i] = ft_strjoin("SHLVL=", num);
		free(num);
	}
	else
		utils->envr[i] = ft_strdup("SHLVL=1");
	utils->exp = bubble_sort(0, utils->envr, 0, argc);
	if (argc != 1 || argv[1])
	{
		printf("invalid args (no args should be used)\n");
		exit (1);
	}
	signal_search(IGNORE);
	while (main2(utils, 0))
		;
	return (0);
}