/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:55:03 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 15:28:25 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_eval_format(t_print *tab, const char *str, int pos)
{
	if (ft_strchr(ENDSYMBOL, str[pos]))
	{
		pos = ft_convert_indicator(tab, str, pos);
		ft_initialize_tab(tab);
		return (pos);
	}
	return (pos);
}
