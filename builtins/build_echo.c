/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:19:40 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/10/17 19:11:55 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

void	echo_printer(char **final_reader, int j, char *arr)
{
	while (final_reader && final_reader[++j])
		ft_putstr_fd(final_reader[j], 1);
	if (echo_flag(arr) == 0)
		ft_putstr_fd("\n", 1);
	free_dptr(final_reader, 0);
}

void	build_echo(char *arr, t_shell *utils, int i, int j)
{
	int		x;
	int		pa;
	char	*str;
	char	**final_reader;

	final_reader = ft_calloc(sizeof(char *), final_reader_size(arr, 0, 0) + 1);
	if (echo_flag(arr) == 1)
		i += flag_count(arr);
	while (arr[i])
	{
		has_quotes(i, 0, arr, utils);
		i = utils->lala[2];
		pa = utils->lala[0];
		x = utils->lala[1];
		str = ft_substr(arr, i, x);
		if (pa > 0)
			i++;
		final_reader[++j] = expansions(str, utils, pa);
		free(str);
		i += x;
	}
	utils->lala[2] = i;
	echo_printer(final_reader, -1, arr);
}
