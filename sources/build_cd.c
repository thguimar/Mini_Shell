/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:33:47 by thguimar          #+#    #+#             */
/*   Updated: 2024/05/21 19:47:35 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include <unistd.h>
#include "../libft/libft.h"
#include <fcntl.h>
#include <fcntl.h>

int	ft_strlen3(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
char	*user_search(char **env)
{
	int		i;
	int		j;
	int		len;
	char	*str;
	int		x;

	i = 0;
	j = 0;
	x = 1;
	len = 0;
	while(env[j])
	{
		while(env[j])
		{
			while(env[j][i])
			{
				if (env[j][i] == 'U' && env[j][i + 1] == 'S' && env[j][i + 2] == 'E' && env[j][i + 3] == 'R' && env[j][i + 4] == '=')
				{
					i += 5;
					len = ft_strlen3(&env[j][i]);
					str = ft_calloc(len + 2, sizeof(char));
					while (env[j][i])
					{
						str[0] = '/';
						str[x++] = env[j][i++];
					}
					return (str);
				}
				i++;
			}
			j++;
			i = 0;
		}
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

	home = "/home";
	user = user_search(env);
	home = ft_strjoin(home, user);
	if (argc == 1 || argv[1][0] == '\0')
	{
		if (argc == 1)
			chdir(home);
		printf("%s\n", getcwd(argv[1], 100));
	}
	else if (argc == 2)
	{
		i = 0;
		j = 1;
		if (is_twopoints(argv[1]) == 0)
		{
			str = malloc(ft_strlen3(argv[1]) * sizeof(char) + 2);
			str[0] = '/';
			while (argv[1][i])
			{
				str[j] = argv[1][i];
				//printf("%c\n", str[j]);
				j++;
				i++;
			}
			//printf("%s\n", str);
			printf("%s\n", getcwd(str, 100));
		}
		else if (chdir(argv[1]) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 1);
			ft_putstr_fd(argv[1], 1);
		}
		/*if (is_twopoints(argv[1]) == 1)
			printf("%s\n", getcwd(str, 100));*/
	}
}