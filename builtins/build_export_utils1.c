/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:56:04 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/19 18:03:19 by thguimar         ###   ########.fr       */
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
	printf("%i\n", mlc_size(0, exp));
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

	i = -1;
	j = -1;
	copy = ft_calloc(mlc_size(0, exp) + 1, sizeof(char *));
	while (exp[++j + 1])
	{
		copy[j] = ft_calloc(ft_strlen(exp[j]) + 1, sizeof(char));
		while (exp[j][++i])
			copy[j][i] = exp[j][i];
		i = -1;
	}
	return (copy);
}

char	**bubble_sort(int j, char **mlc, int flag, int argc)
{
	char	**copy;
	char	*shelf;
	int		i;

	i = 0;
	if (flag == 0)
		copy = exp_copy(mlc);
	else
		copy = exp_copy2(mlc, argc);
	j = 0;
	while (copy[j])
	{
		if ((copy[j + 1] != NULL && copy[j] != NULL)
			&& ft_strcmp2(copy[j], copy[j + 1]) > 0)
		{
			shelf = copy[j];
			copy[j] = copy[j + 1];
			copy[j + 1] = shelf;
			j = -1;
			i = -1;
		}
		i++;
		j++;
	}
	return (copy);
}
