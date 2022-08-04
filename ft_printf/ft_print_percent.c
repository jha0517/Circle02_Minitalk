/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:17:32 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 15:28:44 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

void	ft_print_percent(t_print *tab)
{
	char	a;

	a = 37;
	ft_putchar_fd(a, 1);
	tab->nprinted += 1;
}
