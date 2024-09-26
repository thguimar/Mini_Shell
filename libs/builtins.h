/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/09/03 18:04:51 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <dirent.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../pipex/sources/pipex.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>


typedef struct s_status
{
	int	status;
}	t_status;

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

typedef struct s_index
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	x;
}		t_index;

typedef struct s_expansions
{
	int		dollar;
	char 	*o_que_quiser;
	char 	*o_que_quiser2;
	char 	*o_que_quiser3;
	char 	*o_que_quiser4;
	char 	*o_que_quiser5;
	char	*output;
	char	*pid_str;
	char	**split;
}		t_expansions;

typedef struct s_shell
{
	char			**exp;
	char			**envr;
	char			**builtins;
	char			**command;
	//char			***bizarre;
	char			*input;
	int				j;
	int				process_id;
	int				status;
	t_builtvars		*export;
	t_builtvars2	*cd;
	t_expansions	*expansions;
}		t_shell;

typedef struct s_cd
{
	char	*user;
	int		flag;
	char	*str;
	char	*joined;
	int		i;
	int		j;
	int		x;
	t_shell	*utils;
}		t_cd;

typedef struct s_pipe_comms	t_pipe_comms;

typedef struct s_pipe_comms
{
	char				*strp;
	int					*fd_in;
	int					*fd_out;
	t_pipe_comms	*next;
}		t_pipe_comms;

//global char *bultins[2] = {"echo", "cd"};

//Export Functions

char	**bubble_sort(int j, char **mlc, int flag, int argc);
char	**exp_copy(char **exp);
char	**exp_copy2(char **exp, int argc);
int		equal_vars(char **exp, char **argv, int j, int flag);
char	**dptr_dup(char	**dptr);
int		ft_strcmp2(char *s1, char *s2);
int		ft_strlen3(char *str);
int		is_there_equals(char *argv);
int		line_waste(t_builtvars *export, char **argv, int flag, int j);
int		mlc_size(int j, char **mlc);
int		var_equal_line(char **env, char **argv, int j);
int		write_exp2(t_shell *utils, int flag, int j, int i);
int		mlc_size(int j, char **mlc);
void	argc2(t_shell *utils, char **argv, int j, int argc);
void	export_helper(t_builtvars *export, char **argv, int j);
void	export_helper2(char **mlc, char **argv, int i);
void	export_helper_helper(t_builtvars *export, char **argv, int j);
void	export_hha(char **argv, t_builtvars *export, int j, int flag);
void	index_reset(t_shell *utils);
void	write_exp(t_shell *utils);

//Unset Functions

int		ft_strlen4(char *str);
int		there_is_an_equal_argv(char **argv, char *env);
int		unset_argv_checker(char *exp, char **argv);
int		unset_flag(int flag, char *exp, char *argv);
int		var_comp2(char **env, char **argv, int j);
int		var_equal_line2(char **env, char *argv);
void	write_env(int j, char **mlc);

//ECHO FUNCTIONS

char	*ft_strjoinn(char *s1, char *s2);
int		quotes_verify(char *argv);
char	**ft_split2(char *str, char c);
//int		is_there_a_dollar_sign(char *argv);
int		echo_flag(char *argv);
int		echo_func(char *argv, int flag);
int		flag_count(char *argv);
int		in_between(char c, char *str, int i);
//void	is_there_dollar_sign(char *argv, t_shell *utils);

//CD Functions
char	*get_user(char **env, char *str, int i, int j);
char	*user_search(char **env, int i, int j, int len);
int		get_line_value(char **exp, int line);
int		is_twopoints(char *argv);
void	argc_1(t_cd *cd, char *home, int argc, char **argv);
void	argc_2(t_cd *cd, char **argv, t_shell *utils);
void	cd_initialize(t_cd *cd, t_shell *utils);
void	get_cd(t_cd *cd, char **argv, t_shell *utils);


//Env Functions

int		compare_exp_env(t_shell *utils, int i, int j);
void	build_env(int argc, char **argv, t_shell *utils);
void	write_exp_to_env(t_shell *utils, int i, int j);

//BUILTINS
char	**build_export(int argc, char **argv, t_shell *utils);
char	**build_unset(int argc, char **argv, char **exp, int i);
int		builtins(char *str, t_shell *utils, int i);
void	build_cd(int argc, char **argv, char **env, t_shell *utils);
void	build_echo(char *arr, t_shell *utils, int i, int j);
void	build_env(int argc, char **argv, t_shell *utils);
void	build_exit(char **argv, t_shell *utils, int flag);
void	build_pwd(int argc, char **argv);
void	exec_builtin(int flag, char **command, char **env, t_shell *utils);

//PID FUNCTIONS

char	*ft_getpid(void);
void	ft_free_pid(char **pid);

//SIGNALS
void	signal_search(t_signal_type t);

//Pipe Related

bool	is_there_pipe(char *str);
char	**pipping_commands(char *input, t_pipe_comms *pcomms);
char	**pipping_commands2(char *str, int x, t_pipe_comms *pcomms);
int		size_before_pipe(char *str);
int		pipe_verify(char *argv);
char	***scary_thing(char	**dptr);

//Expansion Related

char	*expansions(char *argv, t_shell *utils, int pa);
char	*ft_strjoinn(char *s1, char *s2);
int		is_there_a_dollar(char *str);
int		pid_dollar(char *str, int j);
int		varlen(char *str, int k);

//EXIT
void	final_cleaner(t_shell *utils);
void	free_dptr(char **clc, int i);
void	ft_free(void **pointer);
void	free_tptr(char ***clc, int i);

//COMMANDS
int		builtin_not_command(char **argv);
void	execute_comm(char **argv, char *test2, t_shell *utils, char *test);
void	path_comms(char **argv, t_shell *utils);

//MiniShell Related

int		main2(t_shell *utils, int flag);
void	exec_builtin(int flag, char **command, char **env, t_shell *utils);
void	index_reset(t_shell *utils);
void	input_fixer(char *input);
void	status_handler(t_shell *utils);

t_status *global_status(void);

//tokenizar a string, e depois usar o split para ...
#endif
