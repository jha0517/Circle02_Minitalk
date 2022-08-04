/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 20:21:44 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 15:29:17 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

void	ft_print_str(t_print *tab)
{
	char	*s;
	int		len;

	s = va_arg(tab->args, char *);
	len = 0;
	if (s == NULL)
	{
		s = "(null)";
		len = 6;
	}
	else
		len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	tab->nprinted += len;
}
