/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:22:26 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/22 19:20:49 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../libft/libft.h"

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	if(argc == 1)
	{
		int	j;

		j = 0;
		while(env[j])
		{
			ft_putstr_fd(env[j], 1);
			ft_putstr_fd("\n", 1);
			j++;
		}
	}
}