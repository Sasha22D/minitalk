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
			bit_index = 7;
			unsigned char	temp_char = argv[2][i];
			while (bit_index >= 0)
			{
				if ((temp_char >> bit_index) & 1)
					kill(atoi(argv[1]), SIGUSR1);
				else
					kill(atoi(argv[1]), SIGUSR2);
				usleep(100);
				bit_index--;
			}
			i++;
		}
	}
}