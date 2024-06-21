#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtins.h"
# ifndef PATH
#  define PATH "/home/thguimar/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin"

typedef	struct s_shell
		t_shell;

//MINISHELL.C
void	exec_builtin(int flag, char **command, char **env, t_shell *utils);
void	path_comms(int argc, char **argv, char **env);

# endif

#endif