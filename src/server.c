#include "../includes/minitalk.h"

char	*g_buffer;

char	*str_join_char(char  *s1, char c)
{
	char	*str_out;
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
    str_out = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (!str_out)
		return (0);
	while (s1[i] != '\0')
	{
		str_out[i] = s1[i];
		i++;
	}
	str_out[i] = c; 
	str_out[i+1] = '\0';
	//free(s1);
	return (str_out);
}


void selectFucntion(int signal)
{
	static int flag;

	flag = 0;
	if (flag == 32)
	{
		//malloc
		flag++;
	}
	if (flag < 32)
	{
		//call function to send length
		flag++;
	}
	else
	{
		signal_handler(signal);
		
	}
}

/**
 * SINGAL_HANDLER funtion:
 *
 * */
void signal_handler(int signal)
{
	static char	current_char;
	static int	bit_index;

	current_char = current_char | (signal == SIGUSR1);
	bit_index++;
	if (bit_index == 8)
	{
		if (current_char == '\0')
		{
			//write(1, g_buffer, ft_strlen(g_buffer));
			ft_putstr_fd(g_buffer, 1);
			ft_putchar_fd('\n', 1);
			free(g_buffer); 
		}
		else
			g_buffer = str_join_char(g_buffer, current_char);
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
int main(int argc, char **argv)
{
	pid_t pid;
	

	if (argc != 1)
    {
        ft_putstr_fd("Error: ./server \n", 1);
        return (0);
    }
	(void) argv;
	pid = getpid();
	ft_putstr_fd("Server PID: ", 1); // Change this to ft_printf
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	g_buffer = calloc(1, sizeof(char));
	//Controlar esto
	// signal(SIGUSR1, signal_handler1);
	// signal(SIGUSR2, signal_handler1);
	// while (1)
	// 	pause();

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	free(g_buffer);
	return (0);
}
