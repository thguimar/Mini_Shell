/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:14:19 by joana             #+#    #+#             */
/*   Updated: 2024/10/19 20:15:59 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	increase_shlvl(t_shell *utils)
{
	int		i;
	int		n;
	char	*num;

	i = 0;
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
}

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

void	exec_builtin(int flag, t_pipe_comms *pcomms, char **env, t_shell *utils)
{
	if (utils->input)
		input_fixer(utils->input);
	if (flag == 1)
		build_echo(utils->input, utils, pcomms);
	else if (flag == 2)
		build_cd(pcomms->argc, pcomms->args, env, utils);
	else if (flag == 3)
		build_pwd(pcomms->argc, pcomms->args);
	else if (flag == 4)
		utils->exp = build_export(pcomms->argc, pcomms->args, utils);
	else if (flag == 5)
		utils->exp = build_unset(pcomms->argc, pcomms->args, utils->exp, -1);
	else if (flag == 6)
		build_env(pcomms->argc, pcomms->args, utils);
	else if (flag == 7)
		build_exit(pcomms->args, utils, 1, 0);
}

void	ft_split_args_in_comms(t_pipe_comms *pcomms, t_shell *utils)
{
	t_pipe_comms	*temp;
	int				i;

	temp = pcomms;
	i = 0;
	while (temp)
	{
		temp->args = ft_split_args(pcomms->strp);
		while (temp->args[i])
		{
			has_quotes(0, 0, temp->args[i], utils);
			temp->args[i] = ft_substr(temp->args[i], utils->lala[2], \
			utils->lala[1]);
			if (utils->lala[0] > 0)
				i++;
			temp->args[i] = expansions(temp->args[i], utils, utils->lala[0]);
			i++;
		}
		i = 0;
		temp = temp->next;
	}
}

void	pcomms_arg_count(t_pipe_comms *pcomms)
{
	t_pipe_comms	*temp;
	int				i;
	int				count;

	i = -1;
	count = 0;
	if (!pcomms)
		return ;
	temp = pcomms;
	while (temp)
	{
		while (temp->args[++i])
			count++;
		temp->argc = count;
		count = 0;
		i = -1;
		temp = temp->next;
	}
}
