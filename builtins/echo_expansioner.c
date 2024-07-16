/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_expansioner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thiago-campus42 <thiago-campus42@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:38:35 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/07/16 19:27:47 by thiago-camp      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

int quotes_verify(char c, char *argv, int j)
{
	int	x;

	x = 1;
	while (argv[j])
	{
		if (argv[j] == c)
			x++;
		j++;
	}
	return (x);
}

void	writter(char *argv)
{
	int		j;
	char	*str;
	int		x;

	j = 0;
	x = 0;
	str = ft_calloc(ft_strlen(argv) + 1, sizeof(char));
	while (argv[j])
	{
		if (argv[j] != '\'')
		{
			str[x] = argv[j];
			x++;
		}
		j++;
	}
	ft_putstr_fd(str, 1);
	free(str);
}

char	*quotes(char *argv)
{
	int	j;
//	int	flag;

//	flag = 0;
	j = 0;
	while (argv[j])
	{
		if (argv[j] == '\'')
		{
			j++;
			if (quotes_verify('\'', argv, j) % 2 != 0)
				return (printf("Odd Quotes\n"), NULL);
			break ;
		}
		else if (argv[j] == '"')
		{
			//flag = 1;
			j++;
			if (quotes_verify('"', argv, j) % 2 != 0)
				return (printf("Odd Quotes\n"), NULL);
			break ;
		}
		j++;
	}
	/*if (flag == 1)
		expansioner();
	else*/
		writter(argv);
	return (NULL);
}
