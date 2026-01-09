/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:21:16 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/19 11:50:20 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		total_size;
	void		*ptr;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
/*
#include <stdio.h>
#include <stdlib.h>
void	print_memory(unsigned char *mem, size_t n)
{
	for (size_t i = 0; i < n; i++)
		printf("%02X ", mem[i]);
	printf("\n");
}
int	main()
{
	size_t	nmemb = 10;
	size_t	size = sizeof(char);

	char	*ptr1 = ft_calloc(nmemb, size);
	
	char	*ptr2 = calloc(nmemb, size);

	if (!ptr1 || !ptr2)
	{
		free(ptr1);
		free(ptr2);
		return 1;
	}

	print_memory((unsigned char *)ptr1, nmemb * size);

	print_memory((unsigned char *)ptr2, nmemb * size);

	free(ptr1);
	free(ptr2);
}
*/
