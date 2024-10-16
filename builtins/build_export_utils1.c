/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:56:04 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/16 17:37:28 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	mlc_size(int j, char **mlc)
{
	while (mlc[j])
		j++;
	return (j);
}

int	ft_strcmp2(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	**exp_copy2(char **exp, int argc)
{
	int		i;
	int		j;
	char	**copy;

	i = -1;
	j = -1;
	copy = ft_calloc(mlc_size(0, exp) + argc, sizeof(char *));
	while (exp[++j])
	{
		copy[j] = ft_calloc(ft_strlen(exp[j]) + 1, sizeof(char));
		while (exp[j][++i])
			copy[j][i] = exp[j][i];
		i = -1;
	}
	return (copy);
}

char	**exp_copy(char **exp)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	j = 0;
	while (exp[i])
		i++;
	copy = ft_calloc(sizeof(char *), i + 1);
	while (exp[j])
	{
		copy[j] = ft_strdup(exp[j]);
		j++;
	}
	return (copy);
}

char	**bubble_sort(int j, char **mlc, int flag, int argc)
{
	char		**copy;
	char		*shelf;
	static int	x;

	if (flag == 0)
		copy = exp_copy(mlc);
	else
		copy = exp_copy2(mlc, argc);
	j = 0;
	if (mlc && x == 1)
		free_dptr(mlc, 0);
	x = 1;
	while (copy[j + 1] && copy[j])
	{
		if ((copy[j + 1] != NULL && copy[j] != NULL)
			&& ft_strcmp2(copy[j], copy[j + 1]) > 0)
		{
			shelf = copy[j];
			copy[j] = copy[j + 1];
			copy[j + 1] = shelf;
			j = -1;
		}
		j++;
	}
	return (copy);
}
