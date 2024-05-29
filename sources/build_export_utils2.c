/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:45:35 by joanda-s          #+#    #+#             */
/*   Updated: 2024/05/29 19:09:17 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

void	struct_initialize_export(t_builtvars *export, char **env, int argc)
{
	export->mlc = exp_calloc(export, env, argc);
	export->k = 0;
	export->l = 0;
	export->m = 0;
	export->n = 0;
	export->x = 0;
	export->j = 0;
	export->i = 0;
	export->flag = 0;
}
