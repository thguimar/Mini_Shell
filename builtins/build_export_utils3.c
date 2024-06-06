/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_export_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:45:38 by joanda-s          #+#    #+#             */
/*   Updated: 2024/06/06 06:22:44 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

int	mlc_size(int j, char **mlc)
{
	while (mlc[j])
		j++;
	return (j);
}
char	**bubble_joanda(int j, char **mlc)
{
	char	*shelf1;
	char	*shelf2;
	int		i;

	j = mlc_size(j, mlc);
	i = 0;
	while(mlc[i])
	{
		if ((mlc[j] != NULL && \
		mlc[i] != NULL) && ft_strcmp2(mlc[i], mlc[j]) > 0)
		{
			shelf1 = mlc[i];
			mlc[i] = mlc[j];
			i++;
			if (mlc[i] != NULL)
			{
				shelf2 = mlc[i];
				mlc[i] = shelf1;
			}
		}
		if (mlc[i] != NULL)
			i++;
	}
	return (mlc);
}

char	**bubble_sort(int j, char **mlc)
{
	char	*shelf;

	j = 0;
	while (mlc[j])
	{
		if ((mlc[j + 1] != NULL && \
		mlc[j] != NULL) && ft_strcmp2(mlc[j], mlc[j + 1]) > 0)
		{
			//printf("ft_strcmp2(mlc[j], mlc[j + 1]): %i\n", ft_strcmp2(mlc[j], mlc[j + 1]));
			shelf = mlc[j];
			mlc[j] = mlc[j + 1];
			mlc[j + 1] = shelf;
			j = 0;
		}
		j++;
	}
	return (mlc);
}

void	write_exp(t_builtvars *export)
{
	export->mlc = bubble_sort(export->j, export->mlc);
	export->mlc = bubble_sort(export->j, export->mlc);
	while (export->mlc[export->j])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(export->mlc[export->j], 1);
		ft_putstr_fd("\n", 1);
		export->j++;
	}
	export->mlc[export->j] = NULL;
}

void	exp_calloc_helper(t_builtvars *export, char **env)
{
	export->mlc[export->j][export->i] = env[export->j][export->x];
	if (export->mlc[export->j][export->i] == '=' && export->flag == 0)
	{
		export->flag = 1;
		export->i++;
		export->mlc[export->j][export->i] = '"';
	}
	export->i++;
	export->x++;
}

char	**exp_calloc(t_builtvars *export, char **env, int argc)
{
	while (env[export->j + 1])
		export->j++;
	if (argc == 1)
		export->mlc = ft_calloc((export->j + 1), sizeof(char *));
	else
		export->mlc = ft_calloc((export->j + argc + 1), sizeof(char *));
	export->j = 0;
	while (env[export->j + 1])
	{
		export->i = 0;
		while (env[export->j][export->i])
			export->i++;
		export->mlc[export->j] = ft_calloc(export->i + 3, sizeof(char));
		export->i = 0;
		export->x = 0;
		while (env[export->j][export->x])
			exp_calloc_helper(export, env);
		export->flag = 0;
		export->mlc[export->j][export->i] = '"';
		export->j++;
	}
	return (bubble_sort(export->j, export->mlc));
}
