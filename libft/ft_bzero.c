/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:04:50 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/19 11:39:52 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}
/*
#include <stdio.h>
#include <string.h>

void	print_memory(unsigned char *mem, size_t n)
{
	for (size_t i =0; i<  n; i++)
		printf("%02X ", mem[i]);
	printf("\n");
}

int	main()
{
	char	str1[] = "123456789";
	char	str2[] = "123456789";

	ft_bzero(str1, 5);

	print_memory((unsigned char *)str1, 10);

	bzero(str2, 5);

	print_memory((unsigned char *)str2, 10);
}
*/
