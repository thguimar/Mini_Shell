/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:57:29 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/19 19:18:41 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	final_cleaner(t_shell *utils)
{
	int	i;

	i = 0;
	while (utils->builtins && utils->builtins[i])
	{
		free(utils->builtins[i]);
		printf("%s\n", utils->builtins[i]);
		i++;
	}

	free(utils->builtins);
	i = 0;
	while (utils->exp[i])
	{
		free(utils->exp[i]);
		i++;
	}
	free(utils->exp);
	i = 0;
	while (utils->envr[i])
	{
		free(utils->envr[i]);
		i++;
	}
	free(utils->envr);
}

void	build_exit(t_shell *utils)
{
	final_cleaner(utils);
	exit (1);
}
