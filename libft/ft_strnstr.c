/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:39:22 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/20 12:00:58 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			k = i;
			while (big[k] == little[j] && k < len)
			{
				j++;
				k++;
				if (little[j] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: %s <haystack> <needle> <len>\n", argv[0]);
        return 1;
    }

    const char *haystack = argv[1];
    const char *needle = argv[2];
    size_t len = (size_t)atoi(argv[3]);

    char *res = ft_strnstr(haystack, needle, len);

    if (res)
        printf("Trouvé : %s\n", res);
    else
        printf("Non trouvé\n");

    return 0;
}
*/
