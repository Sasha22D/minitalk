/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:37:17 by sadaniel          #+#    #+#             */
/*   Updated: 2025/11/25 14:53:29 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_print_hex(uintptr_t n, char *base, int *count)
{
	if (n >= 16)
		ft_print_hex(n / 16, base, count);
	write(1, &base[n % 16], 1);
	(*count)++;
}

void	ft_print_memory(void *ptr, char *base, int *count)
{
	uintptr_t	addr;

	addr = (uintptr_t)ptr;
	if (ptr == 0)
	{
		*count += 5;
		ft_putstr("(nil)", *count);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		*count += 2;
		ft_print_hex(addr, base, count);
	}
}

int	ft_putstr(char *s, int count)
{
	if (!s)
	{
		write(1, "(null)", 6);
		count += 6;
		return (count);
	}
	count += ft_strlen(s);
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
	return (count);
}

static int	ft_get_len(long int n, int count)
{
	if (n < 0)
	{
		n = -n;
		count++;
	}
	else if (n == 0)
		return (count + 1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	handle_format(char c, va_list args, va_list args_cpy, int count)
{
	va_copy(args_cpy, args);
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), count + 1);
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *), count));
	else if (c == 'p')
		ft_print_memory(va_arg(args, void *), "0123456789abcdef", &count);
	else if (c == 'd' || c == 'i')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
		return (ft_get_len(va_arg(args_cpy, int), count));
	}
	else if (c == 'u')
	{
		ft_putunsigned(va_arg(args, unsigned int));
		return (ft_get_len(va_arg(args_cpy, unsigned int), count));
	}
	else if (c == 'x')
		ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef", &count);
	else if (c == 'X')
		ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF", &count);
	else if (c == '%')
		return (ft_putchar_fd('%', 1), count + 1);
	return (count);
}
