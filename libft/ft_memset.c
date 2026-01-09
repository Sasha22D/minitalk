/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:09:32 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/19 12:37:47 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = (unsigned char)c;
		p++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>

int main(void)
{
    char str[20] = "Hello World";

    ft_memset(str + 6, 'X', 5);
    printf("Test 1 : %s\n", str);

    ft_memset(str, 'A', 10);
    str[10] = '\0';
    printf("Test 2 : %s\n", str);

    char buffer[10];
    ft_memset(buffer, 'B', 10);
    for (int i = 0; i < 10; i++)
        printf("%c", buffer[i]);
    printf("\n");

    return 0;
}
*/
