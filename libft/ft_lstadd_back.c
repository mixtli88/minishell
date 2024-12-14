/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:15:34 by fwu               #+#    #+#             */
/*   Updated: 2024/09/26 16:35:45 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst)
		{
			tmp = ft_lstlast(*lst);
			tmp->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}

void	ft_ilstadd_back(t_ilist **lst, t_ilist *new)
{
	t_ilist	*tmp;

	if (lst)
	{
		if (*lst)
		{
			tmp = ft_ilstlast(*lst);
			tmp->next = new;
		}
		else
		{
			*lst = new;
		}
	}
}
