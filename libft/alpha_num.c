/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:42:41 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/07/22 16:51:51 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	alpha_num(int c)
{
	if (ft_isalpha(c) == 0 && ft_isdigit(c) == 0)
		return (0);
	return (1);
}

//caso nao seja alpha nem num = 0;
//caso contrario = 1