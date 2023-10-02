#include "../includes/minitalk.h"
//Read PID and message from CLI

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

void send_to_server(int pid_server, unsigned char element){
    int i;
    
    printf("Sending: %c\n", element) ;
    i = 7;
    while (i >= 0)
    {
     
        if(((element >> i) & 1) == 1)
        {
            //printf("1");
            kill(pid_server, SIGUSR1); //Send 1
        }
        else
        {
            //printf("0");
            kill(pid_server, SIGUSR2); //Send 0
        }
        printf("\n");
        usleep(1000);
        i--;
    }

}

int	main(int argc, char **argv)
{
	int		pid_server;
	
	int		i;

	if (argc != 3)
	{
		//TODO: Change printf to ft_printf
		printf("Error: ./client [PID_SERVER] [MESSAGE]\n");
		return (0);
	}

	pid_server = atoi(argv[1]); //Change this to ft_atoi

    printf("PID_SERVER: %d\n", pid_server);
    printf("MESSAGE: %s\n", argv[2]);
	i = 0;
   
	while (argv[2][i]!= '\0')
	{
		send_to_server(pid_server, argv[2][i]);
		i++;
	}
	return (0);
}

