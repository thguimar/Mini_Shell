/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/29 17:00:50 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <dirent.h>
//# include <minishell.h>
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_builtvars
{
	int		j;
	int		i;
	int		l;
	int		m;
	int		k;
	int		n;
	int		x;
	int		flag;
	char	**mlc;
}		t_builtvars;

//int	mini_echo(t_tools *tools, t_simple_cmds *simple_cmd);

#endif
