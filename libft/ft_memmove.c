/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:17:34 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/19 12:32:54 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*o;
	size_t			i;

	i = 0;
	o = (unsigned char *)dest;
	p = (unsigned char *)src;
	if (o == p || n == 0)
		return (dest);
	if (o < p)
	{
		while (i < n)
		{
			*o++ = *p++;
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			o[n] = p[n];
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
    char str[20] = "Hello World";

    ft_memmove(str + 6, str, 5);
    str[11] = '\0';
    printf("Sans overlap  : %s\n", str);

    char str2[20] = "Hello World";

    ft_memmove(str2 + 2, str2, 10);
    str2[12] = '\0';
    printf("Avec overlap  : %s\n", str2);

    return 0;
}
*/
