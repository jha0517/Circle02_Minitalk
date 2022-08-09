/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:44:55 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/09 12:20:10 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minitalk.h"

t_minitalk	g_talkinfo;

char *ft_append_char(char code)
{
	char	*new_string;
	int		i;
	// int		len;
	char	*old_string;

	old_string = g_talkinfo.msg;
	// printf("mystring : %s\n", old_string);
	if (!old_string)
	{
		// printf("===========");
		new_string = (char *)malloc(sizeof(char) * 2);
		new_string[0] = code;
		new_string[1] = '\0';
		// printf("===========");
		return (new_string);
	}
	// printf("code : %c\n", code);
	// printf("len : %zu\n", (ft_strlen(old_string)));
	i = (ft_strlen(old_string));
	new_string = (char *)malloc(sizeof(char) * ((ft_strlen(old_string)) + 2));
	if(!new_string)
		return (NULL);
	new_string = ft_strncpy(new_string, old_string, ft_strlen(old_string));
	// printf("after copy string is : %s\n", new_string);
	new_string[i] = code;
	new_string[i + 1] = '\0';
	// printf("add code string is : %s\n", new_string);
	// free(g_talkinfo.msg);
	g_talkinfo.msg = new_string;
	return (new_string);
}

int	ft_malloc_char_and_send_signal(int id, char code)
{
	int	is_sent;

	is_sent = 0;
	if (code)
	{	g_talkinfo.msg = ft_append_char(code);
		// printf("updated g_talkinfo.msg : %s\n", g_talkinfo.msg);
	}
	else if (code == '\0')
	{
		// printf("end of string: %c\n", code);
		// g_talkinfo.msg = ft_append_char('\n');
		ft_printf("%s\n", g_talkinfo.msg);
		is_sent = kill(id, SIGUSR2);
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
	if (sig == SIGUSR1)
		code = code << 1;
	if (sig == SIGUSR2)
	{
		code = code << 1;
		code += 1;
	}
	count += 1;
	// printf("count : %i\n", count);
	is_sent = kill(theinfo->si_pid, SIGUSR1);
	if (count % 8 == 0)
	{
		is_sent = ft_malloc_char_and_send_signal(theinfo->si_pid, code);
		if (is_sent == -1)
			return ;
		// ft_printf("%c", code);
		code = 0;
		count = 0;
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
