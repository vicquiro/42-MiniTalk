#include "../includes/minitalk.h"

struct s_buffer *g_buffer;



void length_signal_handler(int signal)
{
	static int	msg_length;
	static int	bit_index;

	msg_length = msg_length | (signal == SIGUSR1);
	printf("%d\n", msg_length);
	bit_index++;
	if (bit_index == 32)
		g_buffer->length = msg_length;
	else
		msg_length <<= 1;
}



/**
 * SINGAL_HANDLER funtion:
 *
 * */
void message_signal_handler(int signal)
{
	static char		current_char;
	static int		bit_index;
	static int		msg_index;

	current_char = current_char | (signal == SIGUSR1);
	bit_index++;
	msg_index++;
	if (bit_index == 8)
	{
		printf("%d\n", bit_index);
		if (current_char == '\0')
		{
			ft_putstr_fd(g_buffer->message, 1);
			ft_putchar_fd('\n', 1);
			free(g_buffer->message);
		}
		else
		{
			g_buffer->message[msg_index - 1] = current_char;
			msg_index++;
		}
		bit_index = 0;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

void signal_handler(int signal)
{
	static int flag;

	flag = 0;
	if (flag == 32)
	{
		g_buffer->message = calloc(g_buffer->length, sizeof(char));
		flag++;
	}
	else if (flag < 32)
	{
		length_signal_handler(signal);
		flag++;
	}
	else
		message_signal_handler(signal);
}

/**
 * Main function:
 *  Display PID in stdout
 *  Infinite Loop waiting for signals
 *     -
 */
int main(int argc, char **argv)
{
	pid_t			pid;

	if (argc != 1)
	{
		ft_putstr_fd("Error: ./server \n", 1);
		return (0);
	}
	(void) argv;
	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);


	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	//free(g_buffer); //
	return (0);
}
