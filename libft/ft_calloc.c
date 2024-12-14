/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:45:01 by fwu               #+#    #+#             */
/*   Updated: 2024/02/18 17:58:13 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
	{
		return (0);
	}
	i = 0;
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

// int main(void)
// {
// 	int n;
// 	n = 5;
// 	int *arr = ft_calloc(n, sizeof(int));
// 	int i;

// 	i = 0;
// 	while (i<n)
// 	{
// 		arr[i] = i;
// 		printf("%d", arr[i]);
// 		i++;
// 	}
// }
