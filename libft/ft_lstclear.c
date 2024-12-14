/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:21:44 by fwu               #+#    #+#             */
/*   Updated: 2024/09/30 16:59:38 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (lst && *lst && del)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	lst = 0;
}

void	ft_ilstclear(t_ilist **lst, void (*del)(int))
{
	t_ilist	*tmp;

	while (lst && *lst && del)
	{
		tmp = (*lst)->next;
		ft_ilstdelone(*lst, del);
		*lst = tmp;
	}
	lst = 0;
}
