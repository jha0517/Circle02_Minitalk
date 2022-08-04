/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:44:50 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 15:17:39 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct s_minitalk
{
	char	*msg;
	int		end_of_line;
}	t_minitalk;

int	ft_str_is_numeric(char *str);

#endif
