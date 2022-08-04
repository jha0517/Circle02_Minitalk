/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:04:36 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 15:28:36 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

void	ft_print_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	ft_putchar_fd(a, 1);
	tab->nprinted += 1;
}
