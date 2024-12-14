/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:42:17 by fwu               #+#    #+#             */
/*   Updated: 2024/02/23 13:12:26 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	copy_lst(t_list *old_lst, t_list *new_lst, void *(*f)(void *))
{
	t_list	*next_node;	
	t_list	*new_node;

	while (old_lst && new_lst)
	{
		next_node = old_lst->next;
		if (next_node)
		{
			new_node = ft_lstnew(f(next_node->content));
			if (new_node)
			{
				new_lst->next = new_node;
			}
			else
			{
				return (0);
			}
		}
		new_lst = new_lst->next;
		old_lst = old_lst->next;
	}
	return (1);
}

t_list	*create_lst(t_list *old_lst, void *(*f)(void *))
{
	t_list	*new_node;

	if (old_lst)
	{
		new_node = ft_lstnew(f(old_lst->content));
		if (new_node)
		{
			return (new_node);
		}
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;	

	if (f && del)
	{
		new_lst = create_lst(lst, f);
		if (!copy_lst(lst, new_lst, f))
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		return (new_lst);
	}
	return (0);
}
