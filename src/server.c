/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:29:12 by vquiroga          #+#    #+#             */
/*   Updated: 2023/11/25 14:40:41 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

struct s_buffer g_buffer;

void	length_signal_handler(int signal)
{
	static int	length;
	static int	index;

	length = length | (signal == SIGUSR1);
	index++;
	if (index < 32)
		length <<= 1;
	else
		g_buffer.length = length;
}

/**
 * SINGAL_HANDLER funtion:
 *
 * */
void	message_signal_handler(int signal, int *flag)
{
	static char		current_char;
	static int		bit_index = -1;
	static int		msg_index = 0;

	current_char = current_char | (signal == SIGUSR1);
	if (++bit_index == 7)
	{
		if (current_char == '\0')
		{
			ft_putstr_fd(g_buffer.message, 1);
			ft_putchar_fd('\n', 1);
			msg_index = 0;
			g_buffer.length = 0;
			*flag = 0;
			free(g_buffer.message);
		}
		else
			g_buffer.message[msg_index++] = current_char;
		bit_index = -1;
		current_char = 0;
	}
	else
		current_char <<= 1;
}

void	signal_handler(int signal)
{
	static int	flag;

	//TODO: Kill function send confirmation-signal to client 

	if (flag == 32)
	{
		g_buffer.message = ft_calloc(g_buffer.length + 1, sizeof(char));
		if (!g_buffer.message)
			exit (1);
		flag++;
	}
	if (flag <= 31)
	{
		length_signal_handler(signal);
		flag++;
	}
	else
		message_signal_handler(signal, &flag);
}


int	main(int argc, char **argv)
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
	g_buffer.length = 0;
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
