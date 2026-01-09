/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:04:29 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/09 14:04:29 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

volatile sig_atomic_t	g_server_state = 1;

void	end_message(int signal)
{
	if (signal == SIGUSR2)
		write(1, "Message received!\n", 18);
	exit(EXIT_SUCCESS);
}

void	handler(int signal)
{
	if (signal == SIGUSR1)
		g_server_state = 0;
}

void	send_char(char c, __pid_t server_pid)
{
	int				bit_index;
	unsigned char	temp_char;

	bit_index = 7;
	temp_char = c;
	while (bit_index >= 0)
	{
		if ((temp_char >> bit_index) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit_index--;
		while (g_server_state == 1)
			usleep(42);
		g_server_state = 1;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	__pid_t	server_pid;

	signal(SIGUSR1, handler);
	signal(SIGUSR2, end_message);
	if (argc == 3)
	{
		i = 0;
		server_pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_char(argv[2][i], server_pid);
			i++;
		}
		send_char('\0', server_pid);
	}
	else
	{
		write(1, "Use : ./client PID string\n", 27);
		return (EXIT_FAILURE);
	}
}
