#include <signal.h>
#include <unistd.h>
#include <stdio.h>

// #define SIG1 44;

void signalhandler1(int sig)
{
	// (void) sig;
	// int i = sig;
	// printf("0");
	if (sig == 10)
	{
		printf("-10-");
	}
	// printf("Received signal with number %d\n", sig);
}

int main()
{
	int	i = getpid();
	// int j;
	// int b = 0;
	struct sigaction sa;
	// sigset_t sigset;

	sa.sa_handler = &signalhandler1;
	sa.sa_flags =SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("process id : %d\n", i);
	printf("Waiting for sigals...\n");
	while (1)
	{
		usleep(30);
		// j = pause();
		// printf("signal received ? : %i, id : %i, time : %i\n", j, i, b);
		// b++;
	}
	return (0);
}