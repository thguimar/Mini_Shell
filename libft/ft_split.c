/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:11:00 by thguimar          #+#    #+#             */
/*   Updated: 2023/10/18 14:13:42 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	imlc;
	int	strsize;

	imlc = 0;
	strsize = 0;
	while (s[imlc])
	{
		while (s[imlc] == c)
			imlc++;
		if (s[imlc])
		{
			strsize++;
			while (s[imlc] && s[imlc] != c)
			{
				imlc++;
			}
		}
	}
	return (strsize);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		imlc;
	int		j;
	int		i;

	imlc = 0;
	rtn = ft_calloc(ft_countwords(s, c) + 1, sizeof(char *));
	if (!rtn)
		return (NULL);
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		i = 0;
		while (s[j + i] != c && s[j + i])
			i++;
		if (i > 0)
			rtn[imlc++] = ft_substr(s, j, i);
		j += i;
	}
	return (rtn);
}
