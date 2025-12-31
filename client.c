#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int	i;
	int	bit_index;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i])
		{
			bit_index = 0;
			unsigned char	temp_char = argv[2][i];
			while (bit_index < 8)
			{
				if (temp_char & 0x01)
					kill(atoi(argv[1]), SIGUSR1);
				else
					kill(atoi(argv[1]), SIGUSR2);
				bit_index++;
				temp_char = temp_char >> 1;
				usleep(42);
			}
			i++;
		}
	}
}