/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:44:50 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/09 11:50:11 by hyujung          ###   ########.fr       */
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
	int		i;
}	t_minitalk;

int	ft_str_is_numeric(char *str);
int	ft_signal(int id, char c);
int	ft_malloc_char_and_send_signal(int id, char code);

#endif
