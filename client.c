#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile sig_atomic_t server_state = 0;

void	end_message(int signal)
{
	if (signal == SIGUSR2)
		write(1, "Message received!\n", 18);
}

void	handler(int signal)
{
	if (signal == SIGUSR1)
		server_state = 1;
}

int main(int argc, char **argv)
{
	int	i;
	int	bit_index;

	i = 0;
	signal(SIGUSR1, handler);
	signal(SIGUSR2, end_message);
	if (argc == 3)
	{
		while (argv[2][i])
		{
			bit_index = 7;
			unsigned char	temp_char = argv[2][i];
			while (bit_index >= 0)
			{
				if ((temp_char >> bit_index) & 1)
					kill(atoi(argv[1]), SIGUSR1);
				else
					kill(atoi(argv[1]), SIGUSR2);
				bit_index--;
				usleep(42);
				while (server_state == 0)
					usleep(42);
				server_state = 1;
			}
			i++;
		}
	}
}