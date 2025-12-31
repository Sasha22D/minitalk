#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void	sigusr_handler(int signal)
{
	if (signal == SIGUSR1)
		printf("\nSIGUSR1 received!\n");
	else if (signal == SIGUSR2)
		printf("\nSIGUSR2 received!\n");
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