/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:23:32 by joana             #+#    #+#             */
/*   Updated: 2024/10/19 18:39:47 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

char	*ft_skip_spaces(char *str)
{
	char	*temp;

	if (!str)
		return (NULL);
	temp = str;
	while (*temp && (*temp == ' ' || *temp == '\t'))
		temp++;
	return (temp);
}

char	*ft_ignore_while_not(char *str, char c)
{
	if (*str == c)
		str++;
	while (*str && *str != c)
		str++;
	return (str);
}

int	string_counter(char *str)
{
	char	*temp;
	int		count;

	count = 1;
	if (!str)
		return (count);
	temp = str;
	while (*temp)
	{
		if (*temp == '"')
			temp = ft_ignore_while_not(temp, '"');
		else if (*temp == '\'')
			temp = ft_ignore_while_not(temp, '\'');
		else if (*temp == ' ' || *temp == '\t')
		{
			temp = ft_skip_spaces(temp) - 1;
			count++;
		}
		temp++;
	}
	return (count);
}

char	**ft_split_args(char *str)
{
	int		sub_string_count;
	char	**split;
	char	*s_copy;

	s_copy = str;
	sub_string_count = string_counter(s_copy);
	split = ft_calloc(sub_string_count + 1, sizeof(char *));
	if (!split)
		return (0);
	strings_content2(split, s_copy);
	return (split);
}
