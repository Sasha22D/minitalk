/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:42:22 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/20 16:40:26 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char	*ft_return_empty(char *str)
{
	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;
	char	*p;

	start = 0;
	str = NULL;
	if (s1[0] == '\0')
		return (str = ft_return_empty(str), str);
	end = ft_strlen(s1) - 1;
	while (ft_isinset(s1[start], set) == 1)
		start++;
	while (end > start && ft_isinset(s1[end], set) == 1)
		end--;
	str = malloc(end - start + 2);
	if (!str)
		return (NULL);
	p = str;
	while (start <= end)
		*p++ = s1[start++];
	*p = '\0';
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s1 = "";
    char *set = "";
    char *trimmed;

    trimmed = ft_strtrim(s1, set);
    if (trimmed)
    {
        printf("Original : '%s'\n", s1);
        printf("Trimmed  : '%s'\n", trimmed);
        free(trimmed);
    }
    else
    {
        printf("ft_strtrim a retourné NULL\n");
    }
}
*/
