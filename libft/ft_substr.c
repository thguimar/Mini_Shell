/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:07:20 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/10 15:19:46 by thguimar         ###   ########.fr       */
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
	substr = malloc(sizeof (char) * (len + 1));
	if (!substr)
		return (NULL);
	substr = ft_memcpy(substr, (const void *)(str + start), len);
	substr[len] = '\0';
	return (substr);
}
