/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uinteger.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:00:49 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 15:29:19 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

void	ft_print_uinteger(t_print *tab)
{
	unsigned int	i;
	char			*s;
	int				len;

	i = va_arg(tab->args, unsigned int);
	s = ft_utoa(i);
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	tab->nprinted += len;
	free(s);
}
