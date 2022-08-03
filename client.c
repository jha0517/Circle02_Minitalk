#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "include/libft.h"
#include "include/minitalk.h"
#include <time.h>

// int is_ready = 1;

// void	ft_received(int sig)
// {
// 	if (sig == SIGUSR1)
// 	{
// 		printf(" ");
// 	}
// 	return ;
// }
void ft_send_byte(int id, char c)
{
	int	shift;
	
	shift = 8;
	while(shift >= 0)
	{
		if (((c >> shift) & 1) == 0)
		{
			// printf("0");
			kill(id, SIGUSR1);
			// pause();
			// usleep(100);
		}
		else if (((c >> shift) & 1) == 1)
		{
			// printf("1");
			kill(id, SIGUSR2);
			// pause();
			// usleep(100);
		}
		shift--;
		usleep(200);
	}
}

void iterate_string(char *octet, int id)
{
	clock_t start = clock();
	while(*octet)
	{
		ft_send_byte(id, *octet);
		octet++;
		// printf("\n");
		usleep(50);
	}
	clock_t end = clock();
	printf("sec vitesse : %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
}

int main(int ac, char **av)
{
	int	id;;

	// signal(SIGUSR1, &ft_received);
	if (ac == 3)
	{	if (ft_str_is_numeric(av[1]))
		{
			id = ft_atoi(av[1]);
			iterate_string(av[2],id);
		}
		else
			printf("id must be an number.\n");
	}
	return (0);
}