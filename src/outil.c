/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:18:50 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/09 11:56:42 by hyujung          ###   ########.fr       */
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
