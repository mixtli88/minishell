/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:15:34 by fwu               #+#    #+#             */
/*   Updated: 2024/09/26 20:33:46 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (new)
		{
			new->next = *lst;
			*lst = new;
		}
	}
}

void	ft_ilstadd_front(t_ilist **lst, t_ilist *new)
{
	if (lst)
	{
		if (new)
		{
			new->next = *lst;
			*lst = new;
		}
	}
}
