/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:44:55 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/12 16:00:09 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

t_minitalk	g_talkinfo;

char	*ft_realloc(char *old_string, int len)
{
	char	*new_string;

	new_string = (char *)malloc(sizeof(char) * len);
	if (!new_string)
		return (NULL);
	new_string = ft_strncpy(new_string, old_string, len);
	free(old_string);
	return (new_string);
}

char	*ft_append_char(char code)
{
	char	*new_string;
	int		len;
	char	*old_string;

	old_string = g_talkinfo.msg;
	if (!old_string)
	{
		new_string = (char *)ft_calloc(2, sizeof(char));
		new_string[0] = code;
		return (new_string);
	}
	len = (ft_strlen(old_string));
	new_string = ft_realloc(old_string, (len + 2));
	new_string[len] = code;
	new_string[len + 1] = '\0';
	return (new_string);
}

int	ft_malloc_char_and_send_signal(int id, char code)
{
	int	is_sent;

	is_sent = 0;
	if (code)
		g_talkinfo.msg = ft_append_char(code);
	else if (code == '\0')
	{
		ft_printf("%s\n", g_talkinfo.msg);
		is_sent = kill(id, SIGUSR2);
		free(g_talkinfo.msg);
		g_talkinfo.msg = NULL;
	}
	return (is_sent);
}

void	ft_message_handler(int sig, siginfo_t *theinfo, void *foo)
{
	static char	code = 0;
	static int	count = 0;
	int			is_sent;

	(void) foo;
	is_sent = 0;
	code = code << 1;
	if (sig == SIGUSR2)
		code += 1;
	count += 1;
	is_sent = kill(theinfo->si_pid, SIGUSR1);
	if (count % 8 == 0)
	{
		is_sent = ft_malloc_char_and_send_signal(theinfo->si_pid, code);
		code = 0;
		count = 0;
	}
	if (is_sent == -1)
	{
		ft_printf("Signal failed\n");
		exit (0);
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
	g_talkinfo.msg = NULL;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
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
