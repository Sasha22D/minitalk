/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:39:54 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/20 12:27:40 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*o;

	o = (unsigned char *)dest;
	p = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		*o = *p;
		p++;
		o++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
int main()
{
	char	*str = "sasha daniel";
	char	dest[20];

	ft_memcpy(dest, str, 10);

	printf("%s\n", dest);
}
*/
