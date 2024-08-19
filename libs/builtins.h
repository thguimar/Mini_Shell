/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/12 15:06:21 by joanda-s         ###   ########.fr       */
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
# include "../pipex/sources/pipex.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <signal.h>

typedef enum e_signal_type
{
	ROOT,
	CHILD,
	HEREDOC,
	IGNORE,
}				t_signal_type;

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

typedef struct s_shell
{
	char			**exp;
	char			**envr;
	char			**builtins;
	char			**command;
	char			*input;
	int				j;
	int				process_id;
	t_builtvars		*export;
	t_builtvars2	*cd;
}		t_shell;

typedef struct s_cd
{
	char 	*user;
	int		flag;
	char	*str;
	char	*joined;
	int		i;
	int		j;
	int		x;
	t_shell	*utils;
}		t_cd;

//global char *bultins[2] = {"echo", "cd"};

//Export Functions

char	**bubble_sort(int j, char **mlc, int flag, int argc);
int		ft_strcmp2(char *s1, char *s2);
int		ft_strlen3(char *str);
int		is_there_equals(char *argv);
int		line_waste(t_builtvars *export, char **argv, int flag, int j);
int		mlc_size(int j, char **mlc);
int		var_equal_line(char **env, char **argv, int j);
void	export_helper(t_builtvars *export, char **argv, int j);
void	export_helper2(t_builtvars *export, char **argv, int i);
void	export_helper_helper(t_builtvars *export, char **argv, int j);
void	index_reset(t_shell *utils);
void	write_exp(t_shell *utils);

//Unset Functions

int		ft_strlen4(char *str);
int		there_is_an_equal_argv(char **argv, char *env);
int		var_comp2(char **env, char **argv, int j);
int		var_equal_line2(char **env, char *argv);
void	write_env(int j, char **mlc);

//ECHO FUNCTIONS

char	*quotes(char *argv, char **exp);

//CD Functions

int		is_twopoints(char *argv);
void	argc_1(t_cd *cd, char *home, int argc, char **argv);
void	argc_2(t_cd *cd, char **argv);

//BUILTINS
char	**build_export(int argc, char **argv, t_shell *utils);
char	**build_unset(int argc, char **argv, char **exp, int i);
int		builtins(char *str, t_shell *utils);
void	build_cd(int argc, char **argv, char **env, t_shell *utils);
void	build_echo(char *arr, char **exp);
void	build_env(int argc, char **argv, t_shell *utils);
void	build_exit(t_shell *utils);
void	build_pwd(int argc, char **argv);

//SIGNALS
void	signal_search(t_signal_type t);

//EXIT
void	free_dptr(char **clc, int i);

//COMMANDS
void	path_comms(int argc, char **argv, char **env, t_shell *utils);
//tokenizar a string, e depois usar o split para ...

#endif
