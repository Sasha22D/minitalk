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
			bit_index = 0;
			my_char = 0;
			return ;
		}
		write(1, &my_char, 1);
		bit_index = 0;
		my_char = 0;
	}
	my_char <<= 1;
	kill(client_pid, SIGUSR1);
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		write(2, "Server doesn't need any arguments\n", 35);
		return (EXIT_FAILURE);
	}
	__pid_t	PID = getpid();
	ft_printf("PID: %d\n", PID);

	struct sigaction	sa;

	sa.sa_sigaction = &sigusr_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}