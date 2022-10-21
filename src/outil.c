/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:18:50 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/12 18:51:05 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include "../include/libft.h"
#include <signal.h>

int	ft_signal(int id, char c)
{
	int	is_sent;

	is_sent = 0;
	if (c == 0)
		is_sent = kill(id, SIGUSR1);
	else if (c == 1)
		is_sent = kill(id, SIGUSR2);
	return (is_sent);
}

void	kill_null(int pid)
{
	int	byte;

	byte = 8;
	while (byte--)
	{
		kill(pid, SIGUSR1);
		usleep(5000000);
	}
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
	return (1);
}
