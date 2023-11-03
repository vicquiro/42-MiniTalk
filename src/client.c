#include "../includes/minitalk.h"
// Read PID and message from CLI

/* Iterates over each char and convert to 8bits
/ and send each bit to server
/
/ In send signal function we send 0 or 1 to server
/ SIGURS1 = 1
/ SIGURS2 = 0
*/

/**
 * In send_signal function, after send each bit
 * we wait (usleep) a few micro-seconds
 */

void send_to_server(int pid_server, unsigned char element)
{
	int i;

	printf("Element: %d\n", element); //TODO: Remove this
	i = 7;
	while (i >= 0)
	{
		if (((element >> i) & 1) == 1)
		{
			printf("Bit: %d\n", 1);
			kill(pid_server, SIGUSR1); // Send 1
		}
		else
		{
			printf("Bit: %d\n", 0);
			kill(pid_server, SIGUSR2); // Send 0
		}

		i--;
		usleep(300);
	}
}

int main(int argc, char **argv)
{
	pid_t		pid_server;
	int			i;
	const char	*message;

	if (argc != 3)
	{
		// TODO: Change printf to ft_printf
		printf("Error: ./client [PID_SERVER] [MESSAGE]\n");
		return (0);
	}
	
	pid_server = atoi(argv[1]); // Change this to ft_atoi
	printf("PID_SERVER: %d\n", pid_server);
	message = argv[2];
	printf("MESSAGE: %s\n", message);

	i = 0;

	while (message[i] != '\0')
	{
		send_to_server(pid_server, message[i]);
		i++;
	}
	send_to_server(pid_server, '\0');
	return (0);
}
