/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:44:52 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/09 12:02:12 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

t_minitalk	g_talkinfo;

void	ft_end_of_line()
{
	// ft_printf("Received : %i letters\n", (i / 8));
	// i = 0;
	g_talkinfo.end_of_line = 1;
	exit(0);
}

int	ft_arg_error_check(int ac, char **av)
{
	int	id;

	if (ac != 3 || !ft_str_is_numeric(av[1]))
	{
		ft_printf("INPUT ERROR : ./client [server id] [message]\n");
		return (0);
	}
	id = ft_atoi(av[1]);
	if (id < 1 || id > PID_MAX)
	{
		ft_printf("PID ERROR : Available Pid range is from 1 to 4194304\n");
		return (0);
	}
	if (!av[2][0])
		return (0);
	g_talkinfo.msg = av[2];
	return (1);
}

// void	ft_send_next_binary(int sig, siginfo_t *theinfo, void *foo)
// {
// 	static int	i = 0;
// 	char		c;
// 	int			is_sent;

// 	(void) foo;
// 	is_sent = 0;
// 	c = g_talkinfo.msg[i / 8];
// 	if (sig == SIGUSR1)
// 	{
// 		i += 1;
// 		c = g_talkinfo.msg[i / 8];
// 		if (!c && g_talkinfo.end_of_line == 1)
// 			ft_end_of_line(i);
// 		else
// 			is_sent = ft_signal(theinfo->si_pid, (c >> (7 - (i % 8))) & 1);
// 		if (is_sent == -1)
// 			return ;
// 		usleep(300);
// 	}
// 	else if (sig == SIGUSR2)
// 		ft_end_of_line(i);
// 	return ;
// }

// void	ft_send_first_binary(int server_pid)
// {
// 	char	c;
// 	int		is_sent;

// 	c = g_talkinfo.msg[0];
// 	is_sent = 0;
// 	if ((c >> 7 & 1) == 0)
// 		is_sent = kill(server_pid, SIGUSR1);
// 	else if ((c >> 7 & 1) == 1)
// 		is_sent = kill(server_pid, SIGUSR2);
// 	if (is_sent == -1)
// 	{
// 		ft_printf("PID ERROR : Pid is not correct.\n");
// 		exit(0);
// 	}
// }
void	ft_signal_handler(int sig, siginfo_t *theinfo, void *foo)
{
	(void) foo;
	(void) theinfo;
	if (sig == SIGUSR2)
		ft_end_of_line();
}

static void	kill_null(int pid)
{
	int	byte = 8;

	while (byte--)
	{
		kill(pid, SIGUSR1);
		usleep(500);
	}
}

void ft_iterate_str_send_signal(int server_pid, char *msg)
{
	g_talkinfo.msg = msg;
	static int	i = 0;
	int	btye;
	int	is_sent;
	char	c;

	is_sent = 0;
	while (msg[i / 8])
	{
		btye = 8;
		printf("%d %% \n", (i / 8));
		while (btye--)
		{
			c = g_talkinfo.msg[i / 8];
			if (!c && g_talkinfo.end_of_line == 1)
				ft_end_of_line();
			else
				is_sent = ft_signal(server_pid, (c >> (7 - (i % 8))) & 1);
			if (is_sent == -1)
				return ;
			i++;
			usleep(1000);
		}
	}
	kill_null(server_pid);
}

int	main(int ac, char **av)
{
	struct sigaction	client_sa;

	ft_memset(&client_sa, 0, sizeof(client_sa));
	client_sa.sa_sigaction = ft_signal_handler;
	client_sa.sa_flags = SA_SIGINFO;
	g_talkinfo.msg = NULL;
	g_talkinfo.end_of_line = 0;
	// sigemptyset(&client_sa.sa_mask);
	// sigaddset(&client_sa.sa_mask, SIGUSR1);
	// sigaddset(&client_sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &client_sa, NULL);
	sigaction(SIGUSR2, &client_sa, NULL);
	if (!ft_arg_error_check(ac, av))
		return (0);
	ft_iterate_str_send_signal(ft_atoi(av[1]), av[2]);
	while (1)
	{
		if (g_talkinfo.end_of_line == 1)
			exit(0);
		pause();
	}
	return (0);
}
