/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:44:43 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/19 12:39:59 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				count++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_strlensep(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s != c)
	{
		s++;
		count++;
	}
	return (count);
}

static char	*ft_strdupsep(char const *s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(ft_strlensep(s, c) + 1);
	if (!str)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_free_tab(char **tab, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	index;
	size_t	i;

	i = 0;
	index = 0;
	tab = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			tab[index] = ft_strdupsep(s + i, c);
			if (!tab[index])
				return (ft_free_tab(tab, index), NULL);
			i += ft_strlensep(tab[index], c);
			index++;
		}
	}
	tab[index] = NULL;
	return (tab);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char **tab;
    int i = 0;

    tab = ft_split("sasha paul pierre michel daniel mousel", ' ');

    while (tab[i])
    {
        printf("%s\n", tab[i]);
        free(tab[i]);
        i++;
    }
    free(tab);

    return 0;
}
*/
