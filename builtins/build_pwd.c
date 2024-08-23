/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pwd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:49:53 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/21 17:22:32 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	build_pwd(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
		ft_putstr_fd(getcwd(argv[1], 100), 1);
	ft_putstr_fd("\n", 1);
}
