#include "../includes/minitalk.h"

#define END_TRANSMISSION '\0'
// void convertToBinary(unsigned a)
// {
// 	if (a > 1)
// 		convertToBinary(a / 2);
// 	printf("%d", a % 2);
// }
/**
 * SINGAL_HANDLER funtion:
 *
 * */
void signal_handler(int signal)
{
	static unsigned char current_char;
	static int bit_index;

	// convertToBinary(current_char);
	// printf("\n");
	// printf("OR\n");
	// convertToBinary(signal == SIGUSR1);
	// printf("\n");
	current_char = current_char | (signal == SIGUSR1);
	// printf("__________________\n");
	// convertToBinary(current_char);
	// printf("\n");
	
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == END_TRANSMISSION)
			printf("\n"); // TODO: Change this to ft_printf
		else
			printf("%c", current_char); // TODO: Change this to ft_printf
		bit_index = 0;
		current_char = 0;
	}
	else
	{
		current_char <<= 1;
		// printf("-");
		// convertToBinary(current_char);
		// printf("\n");
	}

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
