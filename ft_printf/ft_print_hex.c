/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:14:05 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 15:28:39 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_putnbr_base_len(unsigned int nbr, char *base)
{
	unsigned int	pos;
	unsigned int	len;
	int				hex_len;

	len = 0;
	pos = nbr;
	hex_len = 0;
	while (base[len])
		len++;
	if (nbr < 0)
	{
		pos = -nbr;
		hex_len += 1;
	}
	if (pos >= len)
	{
		ft_putnbr_base_len((pos / len), base);
		hex_len += 1;
	}
	else
		hex_len += 1;
	return (hex_len);
}

char	*convert(unsigned int num, unsigned int base)
{
	static char	representation[] = "0123456789ABCDEFGF";
	static char	buffer[60];
	char		*ptr;

	ptr = &buffer[50];
	*ptr = '\0';
	while (num != 0)
	{
		ptr--;
		*ptr = representation[num % base];
		num /= base;
	}
	return (ptr);
}

void	ft_print_hex(t_print *tab, char c)
{
	char			*s;
	unsigned int	i;
	int				len;

	i = va_arg(tab->args, unsigned int);
	if (i == 0)
		s = "0";
	else
		s = convert(i, 16);
	len = ft_strlen(s);
	if (c == 'x')
		s = ft_tolowerstr(s);
	ft_putstr_fd(s, 1);
	tab->nprinted += len;
	if (c == 'x')
		free(s);
}
