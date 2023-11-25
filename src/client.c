/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:29:18 by vquiroga          #+#    #+#             */
/*   Updated: 2023/11/25 14:49:34 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	send_message_to_server(int pid_server, unsigned char element)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (((element >> i) & 1) == 1)
		{
			printf("Bit: %d\n", 1);//Remove this 
			kill(pid_server, SIGUSR1); // Send 1
		}
		else
		{
			printf("Bit: %d\n", 0); //Remove this
			kill(pid_server, SIGUSR2); // Send 0
		}
		i--;
		usleep(500);
	}
}

void	send_length_to_server(int pid_server, unsigned int msg_length)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (((msg_length >> i) & 1) == 1)
		{
			printf("Bit: %d\n", 1); //Remove this
			kill(pid_server, SIGUSR1); // Send 1
		}
		else
		{
			printf("Bit: %d\n", 0); // Remove this
			kill(pid_server, SIGUSR2); // Send 0
		}
		i--;
		usleep(500);
	}

}

int	main(int argc, char **argv)
{
	pid_t		pid_server;
	int			i;
	const char	*message;

	if (argc != 3)
	{
		ft_putstr_fd("Error: ./client [PID_SERVER] [MESSAGE]\n", 1);
		return (0);
	}

	pid_server = atoi(argv[1]); // Change this to ft_atoi
	
	ft_putstr_fd("PID_SERVER: ", 1);//Remove this
	ft_putstr_fd(pid_server, 1);//Remove this
	
	message = argv[2];
	printf("MESSAGE: %s\n", message);//Remove this

	i = 0;
	send_length_to_server(pid_server, ft_strlen(message));
	while (message[i] != '\0')
	{
		send_message_to_server(pid_server, message[i]);
		i++;
	}
	send_message_to_server(pid_server, '\0');
	return (0);
}
