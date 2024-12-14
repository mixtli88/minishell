/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:15:34 by fwu               #+#    #+#             */
/*   Updated: 2024/09/26 13:54:01 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = (t_list *)malloc(sizeof(t_list));
	if (!t)
	{
		return (0);
	}
	t->content = content;
	t->next = 0;
	return (t);
}

t_ilist	*ft_ilstnew(int content)
{
	t_ilist	*t;

	t = (t_ilist *)malloc(sizeof(t_ilist));
	if (!t)
	{
		return (0);
	}
	t->content = content;
	t->next = 0;
	return (t);
}

// int main(void)
// {
// 	char *s = "abcde";
// 	t_list *t = ft_lstnew(s);
// 	printf("%s", t->content);
// 	return (0);
// }
