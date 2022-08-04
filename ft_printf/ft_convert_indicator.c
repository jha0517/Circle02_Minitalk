/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_indicator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:03:32 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 15:28:22 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_convert_indicator(t_print *tab, const char *str, int pos)
{
	if (str[pos] == 'c')
		ft_print_char(tab);
	if (str[pos] == 's')
		ft_print_str(tab);
	if (str[pos] == 'p')
		ft_print_address(tab);
	if (str[pos] == 'u')
		ft_print_uinteger(tab);
	if (str[pos] == 'd' || str[pos] == 'i')
		ft_print_integer(tab);
	if (str[pos] == 'x' || str[pos] == 'X')
		ft_print_hex(tab, str[pos]);
	if (str[pos] == '%')
		ft_print_percent(tab);
	return (pos + 1);
}
