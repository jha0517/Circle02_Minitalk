#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "include/libft.h"
#include "include/minitalk.h"
#include <time.h>

void print_bit(char octet, int id)
{
	int	shift = 0;
	char	out;

	while(shift < 8)
	{
		out = ((octet >> shift) & 1) + '0';
		if(out == '0')
		{	kill(id, SIGUSR1);
			printf("0");
		}
		if(out == '1')
		{	kill(id, SIGUSR2);
			printf("1");
		}
		shift++;
	}
	write(1, "\n", 1);
}
void ft_binary_send(int server_id, char c)
{
	(void) server_id;
	(void) c;
	return ;
}
void	ft_send_message(int server_id, char *msgs)
{
	int idx;

	clock_t start = clock();
	idx = 0;
	while (msgs[idx] != '\0')
	{
		ft_binary_send(server_id, msgs[idx]);
		idx++;
	}
	ft_binary_send(server_id, '\0');
	clock_t end = clock();
	printf("sec vitesse : %lf\n", (double)(end - start)/CLOCKS_PER_SEC);
}

int main(int ac, char **av)
{
	int	id;;

	if (ac == 3)
	{	if (ft_str_is_numeric(av[1]))
		{
			id = ft_atoi(av[1]);
			print_bit('a',id);
			// ft_send_message(id, av[2]);
		}
		else
			printf("id must be an number.\n");
	}
	return (0);
}