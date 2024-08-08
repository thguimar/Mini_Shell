/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago-campus42 <thiago-campus42@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:37:42 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/08/02 16:53:21 by thiago-camp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *argv, char **env, t_pipe *p, int	i)
{
	if (ft_strcmp(argv, "/", 1) == 0)
	{
		if (access(argv, X_OK) == 0)
		{
			if (!env || !env[0])
				p[i].path_p = ft_strdup(argv);
			p[i].command = ft_calloc (2, sizeof(char *));
			p[i].command[0] = ft_strdup(ft_strrchr(argv, '/') + 1);
			p[i].command[1] = NULL;
		}
		else
		{
			ft_putstr_fd("command ", 2);
			ft_putstr_fd(argv, 2);
			ft_putendl_fd(" not found", 2);
		}
	}
	else
	{
		p[i].command = ft_split(argv, ' ');
		if (!p[i].command || !p[i].command[0])
			ft_putendl_fd("Errado", 2);
		p[i].path_p = NULL;
	}
}

void struct_initialize(t_pipe *p, int i, char **argv, int argc)
{
	while (++i <= p[0].n)
	{
		p[i].id = 0;
		p[i].command = NULL;
		p[i].path_p = NULL;
		p[i].fd[0] = open(argv[argc - 5], O_RDONLY);
		p[i].fd[1] = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}	
}

t_pipe	*cmd_creator(int argc, char **argv, char **env)
{
	t_pipe	*p;
	char	**paths;
	int		i;

	i = 0;
	p = malloc((argc - 2) * sizeof(t_pipe));
	if (!p)
		final_clear();
	p[0].n = 2;
	struct_initialize(p, -1, argv, argc);
	while (++i <= p[0].n)
		execute(argv[i + 2], env, p, i);
	paths = pick_paths(env);
	search_path(p, paths);
	return (p);
}

int	main(int argc, char **argv, char **env)
{
	t_pipe	*p;
	int		i;
	char	**paths;

	i = 0;
	if (argc < 5)
	{
		ft_putstr_fd("not enough arguments\n");
		return (0);
	}
	p = cmd_creator(argc, argv, env);
}