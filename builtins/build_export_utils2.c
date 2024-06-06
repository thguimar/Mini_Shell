/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:45:35 by joanda-s          #+#    #+#             */
/*   Updated: 2024/06/06 06:24:00 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

void	struct_initialize_export(t_shell *utils, char **env, int argc)
{
	if (!utils->export->mlc)
		utils->export->mlc = exp_calloc(utils->export, env, argc);
	utils->export->k = 0;
	utils->export->l = 0;
	utils->export->m = 0;
	utils->export->n = 0;
	utils->export->x = 0;
	utils->export->j = 0;
	utils->export->i = 0;
	utils->export->flag = 0;
}
