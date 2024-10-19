/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_expansioner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:38:35 by thiago-camp       #+#    #+#             */
/*   Updated: 2024/10/19 20:34:13 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"
#include "../libft/libft.h"

// array[0] -> sq1 (position of the first single quote);
// array[1] -> sq2 (position of the second single quote);
// array[2] -> dq1 (position of the first double quote);
// array[3] -> dq2 (position of the second double quote);
// array[4] -> dq (number of double quotes);
// array[5] -> sq (number of single quotes);

void	array_initializer(int *array, int i)
{
	while (++i < 6)
		array[i] = 0;
}

void	quotes_verify_helper(char *argv, int *array, int j)
{
	while (argv[++j])
	{
		if (argv[j] == '\'' && array[5] % 2 == 0)
		{
			array[0] = j;
			array[5]++;
		}
		else if (argv[j] == '\'' && array[5] % 2 != 0)
		{
			array[1] = j;
			array[5]++;
		}
		else if (argv[j] == '"' && array[4] % 2 == 0)
		{
			array[2] = j;
			array[4]++;
		}
		else if (argv[j] == '"' && array[4] % 2 != 0)
		{
			array[3] = j;
			array[4]++;
		}
	}
}

int	quotes_verify(char *argv)
{
	int	array[6];

	array_initializer(array, -1);
	quotes_verify_helper(argv, array, -1);
	if (array[5] % 2 != 0 || array[4] % 2 != 0 \
	|| array[5] % 2 == 0 || array[4] % 2 == 0)
	{
		if ((array[4] % 2 == 0 && array[5] % 2 != 0) \
		|| (array[5] % 2 == 0 && array[4] % 2 != 0))
			return (write(1, "Incorrect opening of quotes\n", 28), 1);
		else if (array[4] % 2 != 0 || array[5] % 2 != 0)
			return (write(1, "Incorrect opening of quotes\n", 28), 1);
		else if (array[5] % 2 == 0 || array[4] % 2 == 0)
		{
			if ((array[0] > array[2] && array[1] < array[3]) \
			|| (array[2] > array[0] && array[3] < array[1]))
				return (0);
			else if ((array[0] > array[2] && array[0] < array[3]) \
			|| (array[2] > array[0] && array[2] < array[1]))
				return (write(1, "Incorrect opening of quotes\n", 28), 1);
		}
	}
	return (0);
}

int	pipe_verify(char *argv, int j, int x)
{
	if (argv && ft_strlen(argv) > 0)
	{
		while (argv[++j] || argv[j - 1] == '|')
		{
			if (j > 0 && argv[j - 1] && argv[j - 1] == '|')
				j--;
			x = 0;
			if (j == 0 && argv[j] == '|')
				return (ft_putendl_fd("wrong pipes", 1), -1);
			if (argv[j] == '|')
			{
				j++;
				while (argv[j] && argv[j] != '|')
				{
					if (argv[j] != ' ')
						x++;
					j++;
				}
				if (x == 0)
					return (ft_putendl_fd("wrong pipes", 1), -1);
			}
		}
	}
	return (0);
}
