/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:35:13 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/03 14:14:50 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dest_len >= dstsize || dstsize == 0)
		return (dstsize + src_len);
	while (src[i] && ((i + dest_len) < (dstsize - 1)))
	{
		dst[i + dest_len] = src[i];
		i++;
	}
	if (i + dest_len < dstsize)
	{
		dst[i + dest_len] = '\0';
	}
	return (src_len + dest_len);
}
