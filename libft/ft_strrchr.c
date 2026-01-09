/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:05:47 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/20 11:46:26 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen(s);
	s += s_len;
	if (*s == (unsigned char)c)
		return ((char *)s);
	while (s_len > 0)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		else
		{
			s--;
			s_len--;
		}
	}
	if (s[0] == (unsigned char)c)
		return ((char *)s);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <string> <char>\n", argv[0]);
        return 1;
    }

    char *str = argv[1];
    char c = argv[2][0];

    char *res = strrchr(str, c);

    if (res)
        printf("Dernière occurrence de '%c' : %s\n", c, res);
    else
        printf("Caractère '%c' non trouvé\n", c);

    return 0;
}
*/
