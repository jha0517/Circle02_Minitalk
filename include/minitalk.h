/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:44:50 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/12 18:53:15 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# define PID_MAX 4194304
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "./ft_printf.h"
# include "../libft/libft.h"

typedef struct s_minitalk
{
	char	*msg;
	int		end_of_line;
	int		total_sent_byte;
}	t_minitalk;

int		ft_str_is_numeric(char *str);
int		ft_signal(int id, char c);
int		ft_malloc_char_and_send_signal(int id, char code);
void	kill_null(int pid);
void	ft_signal_handler(int sig, siginfo_t *theinfo, void *foo);
int		ft_arg_error_check(int ac, char **av);

#endif
