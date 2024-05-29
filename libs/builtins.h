/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/29 19:16:40 by joanda-s         ###   ########.fr       */
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
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	int		n;
	int		x;
	int		flag;
	char	**mlc;
}		t_builtvars;

typedef struct s_builtvars2
{
	int		i;
	int		j;
	int		l;
	int		m;
	int		flag;
	int		tries;
	char	**clc;
}		t_builtvars2;

//Export Functions

char	**bubble_sort(int j, char **mlc);
char	**exp_calloc(t_builtvars *export, char **env, int argc);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen3(char *str);
int		mlc_size(int j, char **mlc);
int		var_comp(char **env, char **argv, int j);
int		var_equal_line(char **env, char **argv, int j);
void	exp_calloc_helper(t_builtvars *export, char **env);
void	export_helper(t_builtvars *export, char **argv);
void	export_helper2(t_builtvars *export, char **argv);
void	export_helper_helper(t_builtvars *export, char **argv);
void	export_helper_helper2(t_builtvars *export, char **argv);
void	line_waste(t_builtvars *export, char **argv, int flag);
void	struct_initialize_export(t_builtvars *export, char **env, int argc);
void	write_exp(int j, char **mlc);

//Unset Functions

int		ft_strlen4(char *str);
int		there_is_an_equal_argv(char **argv, char *env);
int		var_comp2(char **env, char **argv, int j);
int		var_equal_line2(char **env, char *argv);
void	struct_initialize_unset(t_builtvars2 *unset);
void	unset_helper(t_builtvars2 *unset, char **argv, char **env);
void	write_env(int j, char **mlc);

//tokenizar a string, e depois usar o split para ...

#endif
