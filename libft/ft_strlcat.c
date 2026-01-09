/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:08:42 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/19 13:03:32 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;
	size_t	space_left;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	space_left = siz - dst_len - 1;
	if (dst_len >= siz)
		return (siz + src_len);
	else
	{
		while (src[i] && space_left--)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char dest[20] = "Hello, ";
    char *src = "World!";
    size_t n;

    n = ft_strlcat(dest, src, sizeof(dest));
    printf("Résultat : %s\n", dest);
    printf("Valeur retournée : %zu\n", n);

    char dest2[10] = "Hi, ";
    n = ft_strlcat(dest2, src, sizeof(dest2));
    printf("Résultat avec petit buffer : %s\n", dest2);
    printf("Valeur retournée : %zu\n", n);

    return 0;
}
*/
