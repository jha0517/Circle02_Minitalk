#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "./libft/libft.h"

void print_byte(char c)
{
	int	shift;
	
	shift = 8;
	printf("\n*");
	while(shift >= 0)
	{
		if (((c >> shift) & 1) == 0)
		{
			printf("0");
		}
		else if (((c >> shift) & 1) == 1)
		{
			printf("1");
		}
		shift--;
	}
	printf("*\n");
}

void ft_message_handler(int sig, siginfo_t * theinfo, void *foo)
{
	static char	code = 0;
	static int	count = 0;
	// int			i = 0;
	(void) foo;
	(void) theinfo;

	// print_byte(code);
	code = code << 1;
	// print_byte(code);
	
	if (sig == SIGUSR2)
	{
		// printf("1");
		code += 1;
		// kill(theinfo->si_pid, SIGUSR1);
	}	
	else if (sig == SIGUSR1)
	{
		// printf("0");
		// printf("0");
		// kill(theinfo->si_pid, SIGUSR1);
		// code += 0;
	}
	count += 1;
	// printf("\ncount is %i\n", count);
	if (count > 8)
	{
		// ft_putchar_fd('\n', 1);
		// print_byte(code);
		ft_putchar_fd(code, 1);
		// printf("----c is <<%c>>----i is <<%i>>\n", code, count);
		// kill(theinfo->si_pid, SIGUSR1);
		code = 0;
		count = 0;
		usleep(50);
	}
	return ;
}

int main()
{
	pid_t	id = getpid();
	struct sigaction sa;
	sigset_t myset;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = ft_message_handler;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	sigemptyset(&myset);
	sigaddset(&myset, SIGUSR2);
	
	ft_putstr_fd(ft_itoa(id), 1);
	// printf("Waiting for signals...\n");
	while (1)
	{
		pause();
	}

	return (0);
}