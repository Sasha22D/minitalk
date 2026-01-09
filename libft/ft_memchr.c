/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:55:59 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/20 12:10:07 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((unsigned char *)p);
		else
			p++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	char	str[] = "sasha daniel";

	printf("%s\n", (char *)ft_memchr(str, 'a', 12));
	printf("%s\n", (char *)ft_memchr(str, 'l', 12));
	printf("%s\n", (char *)ft_memchr(str, 's', 12));
	printf("%s\n", (char *)ft_memchr(str, 'a', 0));
	printf("%s\n", (char *)ft_memchr(str, 'a', 15));
}
*/
