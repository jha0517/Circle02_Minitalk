#include <signal.h>
#include <unistd.h>
#include <stdio.h>

// #define SIG1 44;

void ft_reverse(char code)
{
	char	out = 0;

	out = out | ((code & 128) >> 7); 
	out = out | ((code & 64) >> 5); 
	out = out | ((code & 32) >> 3); 
	out = out | ((code & 16) >> 1); 
	out = out | ((code & 8) << 3); 
	out = out | ((code & 4) << 5);

	printf("out is : %c\n", out);
	write(1, &out, 1);
}

void ft_message_handler(int sig)
{
	static char	code;
	static int	count;

	count += 1;
	code = code << 1;
	if (sig == SIGUSR1)
	{	code += 1;
		printf("1");
	}
	else
	{
		printf("0");
	}
	printf("count is : %i\n", count);
	if (count == 8)
	{
		printf("\n");
		write(1, &code, 1);
		// ft_reverse(code);
		code = 0;
		count = 0;
	}
}

int main()
{
	int	i = getpid();
	struct sigaction sa;

	sa.sa_handler = &ft_message_handler;
	sa.sa_flags =SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("process id : %d\n", i);
	printf("Waiting for signals...\n");
	while (1)
		usleep(1000);

	return (0);
}