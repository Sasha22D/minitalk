/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:23:07 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/19 12:08:40 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*o;
	size_t			i;

	i = 0;
	p = (unsigned char *)s1;
	o = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (p[i] != o[i])
			return (p[i] - o[i]);
		else
			i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("%d\n", ft_memcmp((const void *)av[1], (const void *)av[2], 12));
	printf("%d\n", memcmp((const void *)av[1], (const void *)av[2], 12));
}
*/
