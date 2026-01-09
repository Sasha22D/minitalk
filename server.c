/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadaniel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:04:38 by sadaniel          #+#    #+#             */
/*   Updated: 2026/01/09 14:04:38 by sadaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

void	sigusr_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	my_char = 0;
	static int				bit_index = 0;
	static __pid_t			client_pid;

	if (info->si_pid)
		client_pid = info->si_pid;
	(void)context;
	if (signal == SIGUSR1)
		my_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		if (my_char == '\0')
		{
			write(1, "\n", 1);
			kill(client_pid, SIGUSR2);
			return (bit_index = 0, my_char = 0);
		}
		write(1, &my_char, 1);
		bit_index = 0;
		my_char = 0;
	}
	my_char <<= 1;
	kill(client_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	__pid_t				server_pid;
	struct sigaction	sa;

	(void)argv;
	server_pid = getpid();
	sa.sa_sigaction = &sigusr_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 1)
	{
		write(2, "Server doesn't need any arguments\n", 35);
		return (EXIT_FAILURE);
	}
	ft_printf("PID: %d\n", server_pid);
	while (1)
		pause();
	return (0);
}
