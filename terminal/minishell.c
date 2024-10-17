/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:42:24 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/17 19:44:24 by joana            ###   ########.fr       */
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

int	andre_count(char *str, char c)
{
	int	i;
	int	quotes;
	int	words;

	i = 0;
	words = 0;
	quotes = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c && quotes == 0)
		{
			if ((str[i] ==  '"' || str[i] == '\'') && quotes == 0)
				quotes = 1;
			i++;
			while ((str[i] !=  '"' && str[i] != '\'') && quotes == 1)
				i++;
			if ((str[i] == '"' || str[i] == '\'') && quotes == 1)
			{
				quotes = 0;
				i++;
			}
		}
		if (str[i] && str[i] != c)
			words++;
	}
	return (words + 1);
}

void	*filldre(char **matrix, char const *str, char c)
{
	int		i;
	int		j;
	int		word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] && str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] && str[i + j] != c)
			{
				j++;
				if ((str[i] ==  '"' || str[i] == '\''))
				{
						j++;
					while (str[i] && str[i] !=  '"' && str[i] != '\'')
						i++;
					if ((str[i] == '"' || str[i] == '\''))
						i++;
				}
			}
		}
			matrix[word++] = ft_substr(str, i, j);
			//if (!matrix[word - 1])
			//	return (free_matrix(matrix, word - 1));
			i += j;
	}
	matrix[word] = NULL;
	return (matrix);
}

char	**split_andre(t_shell *utils)
{
	char	**matrix;
	
	matrix = (char **)malloc(sizeof (char *) * (andre_count(utils->input, ' ') + 1));
	if (!matrix)
		return (NULL);
	matrix = filldre(matrix, utils->input, ' ');
	return (matrix);
}


//utils->input = readline("minishell"); //prompt escreve por cima por causa do prompt ser interativo

int	main2(t_shell *utils, int flag)
{
	t_pipe_comms	*pcomms;
	t_pipe_comms	*test;
	int	i;

	i = 0;
	pcomms = ft_calloc(1, sizeof(t_pipe_comms));
	free_dptr(utils->command, 0);
	signal_search(ROOT);
	printf("global status beginning -> %d\n", global_status()->status);
	index_reset(utils);
	utils->input = readline("\x1b[5;95mpanic_shell> \x1b[0m");
	if (utils->input)
		add_history(utils->input);
	else
		return (free_dptr(utils->envr, 0), free(utils->export), free_dptr(utils->exp, 0), free(utils), 0);
	if (quotes_verify(utils->input, 0, 0, -1) == 0)
	{
		if (pipe_verify(utils->input, -1, 0) == 0)
		{
			utils->command = pipping_commands(utils->input, pcomms);
			test = pcomms;
//			while (test != NULL)
//			{
//				printf("Pcomms; %s\n", test->strp);
//				test = test->next;
//			}
			utils->command = split_andre(utils);
			while (utils->command[i])
			{
				has_quotes(0, 0, utils->command[i], utils);
				utils->command[i] = ft_substr(utils->command[i], utils->lala[2], utils->lala[1]);
				if (utils->lala[0] > 0)
					i++;
				utils->command[i] = expansions(utils->command[i], utils, utils->lala[0]);
				i++;
			}
			while (utils->command[utils->j])
				utils->j++;
			flag = builtins(utils->command[0], utils, -1);
			if (flag == 0)
				path_comms(utils->command, utils, -1, -1);
			if (flag != 0)
				exec_builtin(flag, utils->command, utils->envr, utils);
			utils->j = 0;
			free_dptr(utils->command, 0);
		}
		utils->command = NULL;
	}
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