/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:33:47 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/24 14:50:19 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include <unistd.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include <fcntl.h>
#include "../get_next_line.h"

char	*get_user(char **env, char *str, int j, int i)
{
	int	x;

	x = 1;
	while (env[j][i])
	{
		str[0] = '/';
		str[x++] = env[j][i++];
	}
	return (str);
}

int	is_twopoints(char *argv)
{
	int	i;
	int	flag;

	i = 0;
	flag = 2;
	while (argv[i] == 46)
	{
		i++;
		flag--;
		if (flag == 0)
			return (1);
	}
	return (0);
}
char	*user_search(char **env, int i, int j, int len)
{
	char	*str;
	int		x;

	x = 1;
	while(env[j++])
	{
		while(env[j][i])
		{
			if (env[j][i] == 'U' && env[j][i + 1] == 'S' && env[j][i + 2] == 'E' && env[j][i + 3] == 'R' && env[j][i + 4] == '=')
			{
				i += 5;
				len = ft_strlen(&env[j][i]);
				str = ft_calloc(len + 2, sizeof(char));
				str = get_user(env, str, j, i);
				return (str);
			}
			i++;
		}
		i = 0;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **env)
{
	char	*str;
	int		i;
	int		j;
	char	*user;
	char	*home;
	char	*joined;
	int		flag;

	home = "/home";
	user = user_search(env, 0, 0, 0);
	home = ft_strjoin(home, user);
	free(user);
	flag = 0;
	if (argc == 1 || argv[1][0] == '\0' || argv[1][0] == 47)
	{
		i = 0;
		while (argc == 1 || (argv[1][i] == 47 && argv[1][i]))
		{
			i++;
			if (argc == 1)
			{
				chdir(home);
				break ;
			}
			if (argv[1][i] == '\0')
			{
				chdir("/");
				break ;
			}
		}
	}
	if (argc == 2)
	{
		i = 0;
		j = 1;
		if (chdir(argv[1]) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 1);
			ft_putstr_fd(argv[1], 1);
			ft_putstr_fd("\n", 1);
		}
		else if (is_twopoints(argv[1]) == 0)
		{
			if(argv[1][i] == '/')
				str = ft_calloc(ft_strlen(argv[1]) + 1, sizeof(char));
			else
			{
				str = ft_calloc(ft_strlen(argv[1]) + 2, sizeof(char));
				str[0] = '/';
			}
			while (argv[1][i])
				str[j++] = argv[1][i++];
			joined = ft_strjoin(getcwd(argv[1], 100), str);
			chdir(joined);
			flag = 1;
		}
	}
	if (flag == 1)
	{
		free(str);
		free(joined);
	}
	free(home);
	//printf("%s\n", getcwd(argv[1], 100)); //USAR PARA PROMPT NO FUTURO
}
