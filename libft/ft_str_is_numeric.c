/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:59:33 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 15:19:34 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (!((*str >= 48 && *str <= 57)))
			return (0);
		++str;
	}
	return (1);
}
