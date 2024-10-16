/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_exit_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:33:07 by joana             #+#    #+#             */
/*   Updated: 2024/10/16 17:35:49 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

t_status	*global_status(void)
{
	static t_status	status;

	return (&status);
}
// se for maior que este numero, ele divide, mas mostra o exit
//code como o resto da divisão e não o quociente

void	status_handler(t_shell *utils)
{
	(void)utils;
	if (global_status()->status > 255)
		global_status()->status /= 256;
}