/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_unset_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:44:02 by joanda-s          #+#    #+#             */
/*   Updated: 2024/08/23 17:48:13 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

void	write_env(int j, char **mlc)
{
	while (mlc[j])
	{
		ft_putstr_fd(mlc[j], 1);
		ft_putstr_fd("\n", 1);
		j++;
	}
}

int	ft_strlen4(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1] != '=')
		i++;
	return (i);
}

int	there_is_an_equal_argv(char **argv, char *env)
{
	int	j;

	j = 0;
	while (argv[j])
	{
		if (ft_strncmp(argv[j], env, ft_strlen4(env)) == 0)
			return (0);
		j++;
	}
	return (1);
}

int	var_equal_line2(char **env, char *argv)
{
	int	m;

	m = 0;
	while (env[m])
	{
		if (ft_strncmp(argv, env[m], ft_strlen3(env[m])) == 0)
		{
			printf("m = %d\nenv[%d] -> %s\n", m, m, env[m]);
			return (m);
		}
		m++;
	}
	return (-1);
}

int	var_comp2(char **env, char **argv, int j)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(argv[j], env[i], ft_strlen(argv[j])) == 0)
			return (1);
		i++;
	}
	return (0);
}
