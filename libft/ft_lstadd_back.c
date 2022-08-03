/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 20:11:24 by hyujung           #+#    #+#             */
/*   Updated: 2022/08/03 14:13:54 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(alst && new))
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		tmp = ft_lstlast(*alst);
		tmp->next = new;
	}
}
