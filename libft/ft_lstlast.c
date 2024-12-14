/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:15:34 by fwu               #+#    #+#             */
/*   Updated: 2024/09/26 16:33:09 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != 0 && lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

t_ilist	*ft_ilstlast(t_ilist *lst)
{
	while (lst != 0 && lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}
