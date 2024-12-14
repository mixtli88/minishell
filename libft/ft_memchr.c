/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:00:44 by fwu               #+#    #+#             */
/*   Updated: 2024/02/18 17:58:50 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (src[i] == (unsigned char)c)
		{
			return ((void *)(src + i));
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char s1[7] = "abcabc";
// 	char s2[7] = "abcabc";
// 	printf("memchr:   [%s]\n", memchr(s1, 'c', 6));
// 	printf("ft_memchr:[%s]\n", ft_memchr(s2, 'c', 6));
// }
