/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:14:48 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/19 13:10:46 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	src_len;
	size_t	space_left;

	space_left = siz - 1;
	src_len = ft_strlen(src);
	i = 0;
	if (siz == 0)
		return (src_len);
	while (src[i] && i < space_left)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
int	main()
{
	char	*str = "sasha";
	char	dest[20];

	printf("%zu\n%s\n", ft_strlcpy(dest, str, sizeof(dest)), dest);
}
*/
