/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:03:40 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/19 20:49:28 by joana            ###   ########.fr       */
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

typedef struct s_expansions
{
	int		dollar;
	char	*o_que_quiser;
	char	*o_que_quiser2;
	char	*o_que_quiser3;
	char	*o_que_quiser4;
	char	*o_que_quiser5;
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
	char			*input;
	int				j;
	int				process_id;
	int				status;
	int				*lala;
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

typedef struct s_index
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	x;
}		t_index;

typedef struct s_pipe_comms	t_pipe_comms;

typedef struct s_pipe_comms
{
	char				*strp;
	char				**args;
	int					argc;
	int					*fd_in;
	int					*fd_out;
	t_pipe_comms		*next;
}		t_pipe_comms;

typedef struct s_status
{
	int	status;
}	t_status;

//Builtins
char			**build_export(int argc, char **argv, t_shell *utils);
char			**build_unset(int argc, char **argv, char **exp, int i);
int				builtins(char *str, t_shell *utils, int i);
void			build_cd(int argc, char **argv, char **env, t_shell *utils);
void			build_echo(char *arr, t_shell *utils, t_pipe_comms *pcomms);
void			build_env(int argc, char **argv, t_shell *utils);
void			build_exit(char **argv, t_shell *utils, int flag, int i);
void			build_pwd(int argc, char **argv);
void			exec_builtin(int flag, t_pipe_comms *pcomms, \
				char **env, t_shell *utils);

//CD
char			*get_user(char **env, char *str, int i, int j);
char			*user_search(char **env, int i, int j, int len);
int				get_line_value(char **exp, int line);
void			argc_2(t_cd *cd, char **argv, t_shell *utils);
void			cd_initialize(t_cd *cd, t_shell *utils);
void			change_env_and_export_dash(t_shell *utils, char **argv, \
				t_cd *cd);
void			change_env_and_export_dash_oldpwd(t_shell *utils, \
				char *str2, char *str);
void			change_env_and_export_dash_oldpwd_error(t_shell *utils, \
				char *str2, char *str);
void			change_env_and_export_dash_pwd(t_shell *utils);
void			change_env_and_export_home(t_shell *utils, int m);
void			change_env_and_export_home_home(t_shell *utils);
void			change_env_and_export_home_oldpwd(t_shell *utils, char *str);
void			change_env_and_export_home_pwd(t_shell *utils);
void			change_env_and_export_stuff(t_shell *utils, char **argv, \
				t_cd *cd);
void			change_env_and_export_stuff_oldpwd(t_shell *utils, char *str);
void			change_env_and_export_stuff_pwd(t_shell *utils);
void			get_cd(t_cd *cd, char **argv, t_shell *utils);

//Commands

int				quotes_verify(char *argv);
void			array_initializer(int *array, int i);
void			execute_comm(char **argv, char *test2, t_shell *utils, \
				char *test);
void			quotes_verify_helper(char *argv, int *array, int j);

//Echo

int				echo_flag(char *argv);
int				flag_count(char *argv);
int				in_between(char c, char *str, int i);
void			echo_printer(t_pipe_comms *p_comms, int j, char *arr);
void			has_quotes(int i, int x, char *arr, t_shell *utils);

//Env

int				compare_exp_env(t_shell *utils, int i, int j);
void			write_exp_to_env(t_shell *utils, int i, int j);

//Exit

void			final_cleaner(t_shell *utils);
void			free_dptr(char **clc, int i);

//Expansions

char			*expansioner(t_shell *utils, t_index *index, char *temp);
char			*expansions(char *argv, t_shell *utils, int pa);
char			**ft_split2(char *str, char c);
char			*ft_strjoinn(char *s1, char *s2);
int				in_between(char c, char *str, int i);
int				is_there_a_dollar(char *str);
int				pid_dollar(char *str, int j);
void			expansions_bigger_helper(t_shell *utils, t_index *index);
void			expansions_dollar(t_shell *utils, t_index *index);
void			expansions_exit_code(t_shell *utils, t_index *index);
void			expansions_helper(t_shell *utils, t_index *index);
void			expansions_initializer(t_shell *utils);
void			expansions_smaller_helper(t_index *index, t_shell *utils);
void			expansions_value_found(t_shell *utils, t_index *index);
void			expansions_value_found_helper(t_shell *utils, t_index *index);
void			expansions_value_not_found(t_shell *utils, t_index *index);
void			index_initializer(t_index *index);

//Export

char			**bubble_sort(int j, char **mlc, int flag, int argc);
char			**dptr_dup(char	**dptr);
char			**exp_copy(char **exp);
char			**exp_copy2(char **exp, int argc);
int				equal_vars(char **exp, char **argv, int j, int flag);
int				ft_strcmp2(char *s1, char *s2);
int				ft_strlen3(char *str);
int				is_there_equals(char *argv);
int				line_waste(t_builtvars *export, char **argv, int flag, int j);
int				mlc_size(int j, char **mlc);
int				var_equal_line(char **env, char **argv, int j);
int				write_exp2(t_shell *utils, int flag, int j, int i);
int				mlc_size(int j, char **mlc);
void			argc2(t_shell *utils, char **argv, int j, int argc);
void			export_helper(t_builtvars *export, char **argv, int j);
void			export_helper2(char **mlc, char **argv, int i);
void			export_helper_helper(t_builtvars *export, char **argv, int j);
void			export_hha(char **argv, t_builtvars *export, int j, int flag);
void			index_reset(t_shell *utils);
void			write_exp(t_shell *utils);

//MiniShell Related

int				main2(t_shell *utils);
t_status		*global_status(void);
void			increase_shlvl(t_shell *utils);
void			input_fixer(char *input);
void			main2_helper(t_pipe_comms *pcomms, t_shell *utils);
void			status_handler(t_shell *utils);

//PID Related

char			*ft_getpid(void);
void			ft_free_pid(char **pid);

//Pipe Related

char			**pipping_commands(char *input, t_pipe_comms *pcomms);
char			**pipping_commands2(char *str, int x, t_pipe_comms *pcomms);
int				pipe_verify(char *argv, int j, int x);
t_pipe_comms	*new_pipe_node(void);
void			new_pipe_back(t_pipe_comms **pcomms, t_pipe_comms *new_pipe);

//Signals Related

void			here_signal(int signal, siginfo_t *info, void *context);
void			ignore_signal(struct sigaction *sa, int signal);
void			root_signal(int signal, siginfo_t *info, void *context);
void			signal_search(t_signal_type t);
void			signal_search2(t_signal_type t);

//Splitting arguments related

char			*ft_ignore_while_not(char *str, char c);
char			*ft_skip_spaces(char *str);
char			**ft_split_args(char *str);
char			*ft_split_skip(char *str);
int				string_counter(char *str);
int				ft_str_sz(char *str, int i);
int				ft_sz_in_quotes(char *str, char c);
void			ft_special_strlcpy(char *to, char *from, int size, int i);
void			ft_split_args_in_comms(t_pipe_comms *pcomms, t_shell *utils);
void			path_comms(char **argv, t_shell *utils, int i, int j);
void			pcomms_arg_count(t_pipe_comms *pcomms);
void			strings_content2(char **split, char *str);

//Unset

int				ft_strlen4(char *str);
int				unset_argv_checker(char *exp, char **argv);
int				unset_flag(int flag, char *exp, char *argv);
int				var_equal_line2(char **env, char *argv);

#endif
