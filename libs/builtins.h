/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/18 20:11:32 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <dirent.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "minishell.h"

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

typedef struct s_cd
{
	char	*user;
	int		flag;
	char	*str;
	char	*joined;
	int		i;
	int		j;
}		t_cd;

typedef struct s_stuff
{
	char	**builtins;
}		t_stuff;

typedef struct s_shell
{
	char			**exp;
	char			**envr;
	int				j;
	int				process_id;
	t_builtvars		*export;
	t_builtvars2	*cd;
	t_stuff			*stuff;
}		t_shell;

//Export Functions

char	**bubble_sort(int j, char **mlc, int flag, int argc);
char	**exp_copy(char **exp);
char	**exp_copy2(char **exp, int argc);
int		equal_vars(char **exp, char **argv, int j);
int		ft_strcmp2(char *s1, char *s2);
int		ft_strlen3(char *str);
int		line_waste(t_builtvars *export, char **argv, int flag, int j);
int		mlc_size(int j, char **mlc);
int		var_equal_line(char **env, char **argv, int j);
void	export_helper(t_builtvars *export, char **argv, int j);
void	export_helper2(t_builtvars *export, char **argv, int i);
void	export_helper_helper(t_builtvars *export, char **argv, int j, int flag);
void	export_sos(t_shell *utils, char **argv, int j);
void	index_reset(t_shell *utils);
void	write_exp(t_shell *utils);
void	write_exp_helper(t_shell *utils, int i, int j, int flag);

//Unset Functions

int		ft_strlen4(char *str);
int		there_is_an_equal_argv(char **argv, char *env);
int		unset_argv_checker(char *exp, char **argv);
int		var_comp2(char **env, char **argv, int j);
int		var_equal_line2(char **env, char *argv);
void	struct_initialize_unset(t_builtvars2 *unset);
void	unset_helper(t_builtvars2 *unset, char **argv, char **env);
void	write_env(int j, char **mlc);

//CD Functions

char	*get_user(char **env, char *str, int j, int i);
char	*user_search(char **env, int i, int j, int len);
int		is_twopoints(char *argv);
void	argc_1(t_cd *cd, char *home, int argc, char **argv);
void	argc_2(t_cd *cd, char **argv);

//Env Functions

int		compare_exp_env(t_shell *utils, int i, int j);
void	write_exp_to_env(t_shell *utils, int i, int j);

//Echo Functions

int		echo_flag(char *argv);
int		echo_func(char **argv, int flag);
int		ft_strcmp(char *s1, char *s2);
void	skips(char **argv, int j);

//BUILTINS

char	**build_export(int argc, char **argv, t_shell *utils);
char	**build_unset(int argc, char **argv, char **exp, int i);
int		builtins_id(char *str, t_stuff *stuff);
int		is_there_equals(char *argv);
void	build_cd(int argc, char **argv, char **env);
void	build_echo(char **arr);
void	build_env(int argc, char **argv, t_shell *utils);
void	build_exit(void);
void	build_pwd(int argc, char **argv);
void	idk(t_stuff *stuff);

//tokenizar a string, e depois usar o split para ...

#endif
