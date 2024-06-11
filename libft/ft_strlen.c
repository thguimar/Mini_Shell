/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:09:03 by thguimar          #+#    #+#             */
/*   Updated: 2024/06/11 20:21:35 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	long unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	char s1[] = "caracteressao15";
	printf("%li\n", ft_strlen(s1));
	printf("%li\n", strlen(s1));
}*/
