/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:47:47 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/03 14:15:08 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *str, int j)
{
	int	len;

	len = ft_strlen(str);
	while (0 <= len)
	{
		if (str[len] == (char)j)
			return (&(((char *)str)[len]));
		len--;
	}
	return (NULL);
}
