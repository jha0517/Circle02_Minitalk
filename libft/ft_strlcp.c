/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:32:52 by hyujung           #+#    #+#             */
/*   Updated: 2021/11/25 12:34:58 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*src)
		{
			*(dest + i) = *src;
			src++;
		}
		else if (!*src)
			*(dest + i) = '\0';
		i++;
	}
	return (dest);
}
