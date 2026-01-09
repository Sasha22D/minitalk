/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:59:17 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/19 11:52:21 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static long	ft_abs_val(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_get_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = ft_abs_val(n);
		len++;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	long	clone;
	int		len;

	nb = n;
	clone = ft_abs_val(nb);
	len = ft_get_len(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = '0' + clone % 10;
		clone /= 10;
		len--;
	}
	if (nb < 0)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(113));
	printf("%s\n", ft_itoa(-113));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
}
*/
