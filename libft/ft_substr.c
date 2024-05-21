/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:07:20 by thguimar          #+#    #+#             */
/*   Updated: 2023/10/13 17:57:58 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_tester(unsigned int start, size_t len, char const *s)
{
	if (start > ft_strlen(s))
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	char		*rtn;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	len = len_tester(start, len, s);
	str = (char *)s;
	rtn = (char *)malloc(sizeof (char) * (len + 1));
	if (!rtn)
		return (NULL);
	while (str[i] != '\0')
	{
		if (len > 0 && i >= start)
		{
			rtn[j++] = str[i];
			len--;
		}
		i++;
	}
	rtn[j] = '\0';
	return ((char *)rtn);
}
/*
int	main(void)
{
	printf("%s", ft_substr("Hoje esta chovendo muito", 10, 7));
}*/
