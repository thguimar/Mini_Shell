/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:57:29 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/12 15:20:15 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void ft_free(void **pointer)
{
	if(pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
	}
}

void	final_cleaner(t_shell *utils)
{
	free_dptr(utils->builtins, 0);
	free_dptr(utils->exp, 0);
	free_dptr(utils->command, 0);
	//utils->command[0] = NULL;
	free(utils->export);
	free(utils);
/*	utils->builtins = NULL;
	utils->exp = NULL;
	utils->command = NULL;
	utils->export = NULL;
	utils = NULL;*/

//	printf("AAAAAAAAAAAAAAAAAAAA- utils->command[0]: %s", utils->command[0]);
	/*while (utils->envr[i])
	{
		free(utils->envr[i]);
		i++;
	}*/
	//free(utils->envr);
}

void	build_exit(t_shell *utils)
{
	final_cleaner(utils);
	exit (1);
}
