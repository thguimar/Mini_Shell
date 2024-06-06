/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:45:32 by joanda-s          #+#    #+#             */
/*   Updated: 2024/06/06 06:23:19 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

void	line_waste(t_builtvars *export, char **argv, int flag)
{
	if (flag == 0)
		export->mlc[export->m] = \
		ft_calloc(ft_strlen(argv[export->j]) + 3, sizeof(char));
	if (flag == 1)
		export->mlc[export->i] = \
		ft_calloc(ft_strlen(argv[export->j]) + 3, sizeof(char));
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

int	ft_strlen3(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	return (i);
}

int	var_equal_line(char **env, char **argv, int j)
{
	int	m;

	m = 0;
	while (env[m])
	{
		if (ft_strncmp(argv[j], env[m], ft_strlen3(argv[j])) == 0)
			return (m);
		m++;
	}
	return (0);
}

int	var_comp(char **env, char **argv, int j)
{
	int	m;

	m = 0;
	while (env[m])
	{
		if (ft_strncmp(argv[j], env[m], ft_strlen3(argv[j])) == 0)
			return (1);
		m++;
	}
	return (0);
}
