/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:21:43 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/10 19:57:45 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/minishell.h"

void root_signal(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGINT)
	{
		printf("\n");
		/*rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();*/
	}
}

void	signal_search(t_signal_type t)
{
	static struct sigaction sa;

	if (t == ROOT)
	{
		sa.sa_sigaction = root_signal;
		sa.sa_flags = SA_SIGINFO;
		if (sigemptyset(&sa.sa_mask) != 0)
			return ;
		sigaction(SIGINT, &sa, NULL);
		//ignore_signal(&sa, SIGQUIT);
	}
}