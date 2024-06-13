/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:24:33 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/06/13 22:28:48 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	unset_argv_checker(char *exp, char **argv)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if (ft_strncmp(exp, argv[j], ft_strlen4(argv[j])) == 0)
			return (1);
		j++;
	}
	return (0);
}

char	**build_unset(int argc, char **argv, char **exp, int i)
{
	int		j;
	char	**copy;
	int		flag;

	j = -1;
	flag = 0;
	if (argc > 1)
	{
		while (argv[++j])
		{
			while (exp[++i])
			{
				if (ft_strncmp(exp[i], argv[j], ft_strlen4(argv[j]) == 0))
					flag++;
			}
			i = -1;
		}
		j = -1;
		copy = ft_calloc(mlc_size(0, exp) + 1 - flag, sizeof(char *));
		while (exp[++i])
			if (unset_argv_checker(exp[i], argv) == 0)
				copy[++j] = ft_strdup(exp[i]);
		exp = copy;
	}
	return (exp);
}

//char	**build_unset(int argc, char **argv, char **exp)
//{
//	int		j;
//	int		i;
//	char	**copy;
//	int		flag;
//
//	i = 0;
//	j = 0;
//	flag = 0;
//	if (argc > 1)
//	{
//		while (argv[j])
//		{
//			while (exp[i])
//			{
//				if (ft_strncmp(exp[i], argv[j], ft_strlen4(argv[j]) == 0))
//					flag++;
//				i++;
//			}
//			i = 0;
//			j++;
//		}
//		j = 0;
//		copy = ft_calloc(mlc_size(0, exp) + 1 - flag, sizeof(char *));
//		while (exp[i++])
//		{
//			if (unset_argv_checker(exp[i], argv) == 0)
//			{
//				copy[j] = ft_strdup(exp[i]);
//				j++;
//			}
//		}
//		exp = copy;
//	}
//	return (exp);
//}
//char	**build_unset(int argc, char **argv, char **exp, int flag)
//{
//	int		array[2];
//	char	**copy;
//	
//	array[0] = 0; // i;
//	array[1] = -1; // j;
//	if (argc > 1)
//	{
//		while (argv[++array[1]])
//		{
//			while (exp[++array[0]])
//			{
//				if (ft_strncmp(exp[array[0]], argv[array[1]], ft_strlen4(argv[array[1]]) == 0))
//					flag++;
//			}
//			array[0] = -1;
//		}
//		array[1] = -1;
//		copy = ft_calloc(mlc_size(0, exp) + 1 - array[2], sizeof(char *));
//		while (exp[++array[0]])
//		{
//			if (unset_argv_checker(exp[array[0]], argv) == 0)
//				copy[++array[1]] = ft_strdup(exp[array[0]]);
//		}
//		exp = copy;
//	}
//	return (exp);
//}
