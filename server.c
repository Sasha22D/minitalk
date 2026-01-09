#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

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
			kill(info->si_pid, SIGUSR2);
			bit_index = 0;
			my_char = 0;
			return ;
		}
		write(1, &my_char, 1);
		kill(info->si_pid, SIGUSR1);
		bit_index = 0;
		my_char = 0;
	}
	my_char <<= 1;
}

int main()
{
	__pid_t	PID = getpid();
	printf("PID: %d\n", PID);

	struct sigaction	sa;

	sa.sa_sigaction = &sigusr_handler;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}