/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:57:53 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/20 14:53:35 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*p;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > s_len - start)
		len = s_len - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	p = str;
	while (len--)
		*p++ = s[start++];
	*p = '\0';
	return (str);
}
/*
#include <stdio.h>
int	main()
{
	char	str[] = "sasha daniel";
	char	*dup;

	dup = ft_substr((char const *)str, 4, 12);

	printf("%s\n", dup);

}
*/
