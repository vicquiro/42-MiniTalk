#include "../includes/minitalk.h"


// void convertToBinary(unsigned a)
// {
// 	if (a > 1)
// 		convertToBinary(a / 2);
// 	printf("%d", a % 2);
// }

char	*g_buffer;

char	*str_join_char(char const *s1, char c)
{
	char	*str_out;
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
    str_out = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!str_out)
		return (0);
	while (s1[i] != '\0')
	{
		str_out[i] = s1[i];
		i++;
	}
	free((char *)s1);
	str_out[i] = c; 
	str_out[i+1] = '\0';
	return (str_out);
}

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
		if (current_char == '\0')
		{
			ft_putstr_fd(g_buffer, 1);
			ft_putchar_fd('\n', 1);
			free(g_buffer); 
		}
		else
		{
			//printf("%c", current_char);
			g_buffer = str_join_char(g_buffer, current_char);
		}
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
	g_buffer = calloc(1, sizeof(char));
	//Controlar esto
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	free(g_buffer);
	return (0);
}
