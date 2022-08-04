/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:44:52 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 16:24:15 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "include/libft.h"
#include "include/minitalk.h"
#include "include/ft_printf.h"

t_minitalk	g_talkinfo;

void	ft_end_of_line(int i)
{
	ft_printf("Received : %i letters\n", (i / 8));
	i = 0;
	g_talkinfo.end_of_line = 1;
	exit(0);
}

void	ft_send_next_binary(int sig, siginfo_t *theinfo, void *foo)
{
	static int	i = 0;
	char		c;

	(void) foo;
	c = g_talkinfo.msg[i / 8];
	if (sig == SIGUSR1)
	{
		i += 1;
		c = g_talkinfo.msg[i / 8];
		if (!c && g_talkinfo.end_of_line == 1)
			ft_end_of_line(i);
		else
		{
			if (((c >> (7 - (i % 8))) & 1) == 0)
				kill(theinfo->si_pid, SIGUSR1);
			else if (((c >> (7 - (i % 8))) & 1) == 1)
				kill(theinfo->si_pid, SIGUSR2);
		}
		usleep(200);
	}
	else if (sig == SIGUSR2)
		ft_end_of_line(i);
	return ;
}

void	ft_send_first_binary(int server_pid)
{
	char	c;

	c = g_talkinfo.msg[0];
	if ((c >> 7 & 1) == 0)
		kill(server_pid, SIGUSR1);
	else if ((c >> 7 & 1) == 1)
		kill(server_pid, SIGUSR2);
}

int	ft_arg_error_check(int ac, char **av)
{
	if (ac != 3 || !ft_str_is_numeric(av[1]))
	{
		ft_printf("INPUT ERROR : ./client [server id] [message]\n");
		return (0);
	}
	if (!av[2][0])
		return (0);
	g_talkinfo.msg = av[2];
	return (1);
}

int	main(int ac, char **av)
{
	struct sigaction	client_sa;

	ft_memset(&client_sa, 0, sizeof(client_sa));
	client_sa.sa_sigaction = ft_send_next_binary;
	client_sa.sa_flags = SA_SIGINFO;
	g_talkinfo.msg = NULL;
	g_talkinfo.end_of_line = 0;
	sigaction(SIGUSR1, &client_sa, NULL);
	sigaction(SIGUSR2, &client_sa, NULL);
	if (!ft_arg_error_check(ac, av))
		return (0);
	ft_send_first_binary(ft_atoi(av[1]));
	while (1)
	{
		if (g_talkinfo.end_of_line == 1)
			exit(0);
		pause();
	}
	return (0);
}
