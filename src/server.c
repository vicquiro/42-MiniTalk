#include "../includes/minitalk.h"
/**
 * SINGAL_HANDLER funtion:
 * 
 * */
void	handler_signal(int signal)
{
	if (signal == SIGUSR1)
		printf("1");
	else if (signal == SIGUSR2)
		printf("0");
}

/**
 * Main function:
 *  Display PID in stdout
 *  Infinite Loop waiting for signals
 *     - 
*/
int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("Server PID: %d\n", pid); //Change this to ft_printf

	signal(SIGUSR1, handler_signal);
	signal(SIGUSR2, handler_signal);
	while (1)
		pause();
	return (0);
}

