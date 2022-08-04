/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:44:55 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 16:01:45 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

int	g_count;

void	ft_message_handler(int sig, siginfo_t *theinfo, void *foo)
{
	static char	code = 0;

	(void) foo;
	code = code << 1;
	if (sig == SIGUSR2)
		code += 1;
	kill(theinfo->si_pid, SIGUSR1);
	g_count += 1;
	if (g_count % 8 == 0)
	{
		if (code)
			ft_putchar_fd(code, 1);
		else if (code == '\0')
		{
			ft_putchar_fd('\n', 1);
			kill(theinfo->si_pid, SIGUSR2);
		}
		code = 0;
		g_count = 0;
	}
	return ;
}

int	main(void)
{
	pid_t				id;
	struct sigaction	sa;
	char				*str_id;

	id = getpid();
	ft_memset(&sa, 0, sizeof(sa));
	g_count = 0;
	sa.sa_sigaction = ft_message_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	str_id = ft_itoa(id);
	ft_putstr_fd(str_id, 1);
	ft_putchar_fd('\n', 1);
	free(str_id);
	while (1)
		pause();
	return (0);
}
