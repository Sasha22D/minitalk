#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void	sigusr_handler(int signal)
{
	static unsigned char	my_char = 0;
	static int				bit_index = 0;

	if (signal == SIGUSR1)
		my_char |= 1;
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &my_char, 1);
		bit_index = 0;
		my_char = 0;
	}
	my_char <<= 1;
}

int main()
{
	__pid_t	PID = getpid();
	printf("PID: %d\n", PID);

	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	while (1)
		pause();
	return (0);
}