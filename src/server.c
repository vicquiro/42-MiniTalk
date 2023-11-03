#include "../includes/minitalk.h"

#define END_TRANSMISSION '\0'

/**
 * SINGAL_HANDLER funtion:
 *
 * */
void signal_handler(int signal)
{
	static char current_char;
	static int bit_index;
	//printf("-\n");
	current_char = current_char | (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		//printf("--%c\n", current_char);
		if (current_char == END_TRANSMISSION)
			write(1, "\n", 1); // TODO: Change this to ft_printf
		else
			write(1, &current_char, 1); // TODO: Change this to ft_printf
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;

}

/**
 * Main function:
 *  Display PID in stdout
 *  Infinite Loop waiting for signals
 *     -
 */
int main(void)
{
	pid_t pid;

	pid = getpid();
	printf("Server PID: %d\n", pid); // Change this to ft_printf

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
