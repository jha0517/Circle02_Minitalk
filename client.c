/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:44:52 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/12 19:08:15 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

t_minitalk	g_talkinfo;

void	ft_end_of_line(void)
{
	int	i;

	i = g_talkinfo.total_sent_byte;
	ft_printf("Received %i letter(s).\n", (i / 8) - 1);
	g_talkinfo.end_of_line = 1;
	exit(0);
}

void	ft_signal_handler(int sig, siginfo_t *theinfo, void *foo)
{
	(void) foo;
	(void) theinfo;
	if (sig == SIGUSR1)
		g_talkinfo.total_sent_byte += 1;
	if (sig == SIGUSR2)
		ft_end_of_line();
}

void	ft_get_byte_and_signal(int server_pid, char c, int i)
{
	int	is_sent;

	is_sent = 0;
	if (!c && g_talkinfo.end_of_line == 1)
		ft_end_of_line();
	else
		is_sent = ft_signal(server_pid, (c >> (7 - (i % 8))) & 1);
	if (is_sent == -1)
	{
		ft_printf("SIGNAL FAILURE : server didn't get the signal\n");
		exit (0);
	}
}

void	ft_iterate_str_send_signal(int server_pid, char *msg)
{
	int			byte;
	int			i;

	i = 0;
	g_talkinfo.msg = msg;
	while (msg[i / 8])
	{
		byte = 8;
		while (byte--)
		{
			ft_get_byte_and_signal(server_pid, g_talkinfo.msg[i / 8], i);
			i++;
			usleep(500000);
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
	g_talkinfo.total_sent_byte = 0;
	sigemptyset(&client_sa.sa_mask);
	sigaddset(&client_sa.sa_mask, SIGUSR1);
	sigaddset(&client_sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &client_sa, NULL);
	sigaction(SIGUSR2, &client_sa, NULL);
	if (!ft_arg_error_check(ac, av))
		return (0);
	g_talkinfo.msg = av[2];
	ft_iterate_str_send_signal(ft_atoi(av[1]), av[2]);
	while (1)
	{
		if (g_talkinfo.end_of_line == 1)
			exit(0);
		pause();
	}
	return (0);
}
