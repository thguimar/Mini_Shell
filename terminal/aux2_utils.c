/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:39:24 by joana             #+#    #+#             */
/*   Updated: 2024/10/19 18:39:51 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	ft_sz_in_quotes(char *str, char c)
{
	int	i;

	i = 0;
	if (*str == c)
		str++;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

int	ft_str_sz(char *str, int i)
{
	char	*temp;

	temp = str;
	while (*temp)
	{
		if (*temp == '"')
		{
			i += (ft_sz_in_quotes(temp, '"') + 1);
			temp = ft_ignore_while_not(temp, '"') + 1;
		}
		else if (*temp == '\'')
		{
			i += (ft_sz_in_quotes(temp, '\'') + 1);
			temp = ft_ignore_while_not(temp, '\'') + 1;
		}
		else if (*temp == ' ' || *temp == '\t')
			break ;
		else
		{
			i++;
			temp++;
		}
	}
	return (i);
}

void	ft_special_strlcpy(char *to, char *from, int size, int i)
{
	int	j;

	j = 0;
	while (from[i] && i <= size)
	{
		if (from[i] == '"')
		{
			i++;
			while (from[i] && from[i] != '"')
				to[j++] = from[i++];
			i++;
		}
		else if (from[i] == '\'')
		{
			i++;
			while (from[i] && from[i] != '\'')
				to[j++] = from[i++];
			i++;
		}
		else if (from[i] == ' ' || from[i] == '\t')
			i++;
		else
			to[j++] = from[i++];
	}
}

char	*ft_split_skip(char *str)
{
	char	*temp;

	temp = str;
	while (*temp)
	{
		if (*temp == '"')
			temp = ft_ignore_while_not(temp, '"') + 1;
		else if (*temp == '\'')
			temp = ft_ignore_while_not(temp, '\'') + 1;
		else if (*temp == ' ' || *temp == '\t')
		{
			temp = ft_skip_spaces(temp);
			break ;
		}
		else
			temp++;
	}
	return (temp);
}

void	strings_content2(char **split, char *str)
{
	int	sub_str_sz;
	int	sub_str_index;

	sub_str_index = 0;
	while (*str)
	{
		sub_str_sz = ft_str_sz(str, 0);
		split[sub_str_index] = ft_calloc(sub_str_sz + 1, sizeof(char));
		ft_special_strlcpy(split[sub_str_index], str, sub_str_sz, 0);
		str = ft_split_skip(str);
		sub_str_index++;
	}
}
