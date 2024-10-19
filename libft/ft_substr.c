/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joana <joana@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:07:20 by thguimar          #+#    #+#             */
/*   Updated: 2024/10/18 19:57:17 by joana            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;

	if (!str)
		return (NULL);
	if (len >= ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	if (start > ft_strlen(str))
		len = 0;
	substr = ft_calloc(sizeof(char), len + 1);
	if (!substr)
		return (NULL);
	substr = ft_memcpy(substr, (const void *)(str + start), len);
	substr[len] = '\0';
	return (substr);
}

//char	*ft_substr(char const *s, unsigned int start, size_t len)
//{
//	size_t	i;
//	char	*str;
//
//	i = 0;
//	if (!s)
//		return (NULL);
//	if (len == 0 || start > ft_strlen(s))
//	{
//		str = malloc(1);
//		*str = '\0';
//		return (str);
//	}
//	if (ft_strlen(s) - start >= len)
//		str = (char *)malloc(sizeof(char) * (len + 1));
//	else
//		str = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
//	if (!str)
//		return (NULL);
//	while (s[start] && i < len && start < ft_strlen(s))
//		str[i++] = s[start++];
//	str[i] = '\0';
//	return (str);
//}