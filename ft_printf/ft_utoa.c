/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:03:26 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/04 15:29:28 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"

static void	ft_array(char *str, unsigned long long n, long len)
{
	while (n > 0)
	{
		str[len] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
}

long	ft_len(unsigned long long n)
{
	long	i;

	if (n < 0)
	{
		i = 2;
		n *= -1;
	}
	else
		i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned long long nb)
{
	char				*result;
	long				len;
	unsigned long long	n;

	n = nb;
	len = ft_len(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	ft_array(result, n, len - 1);
	return (result);
}
