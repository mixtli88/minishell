/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:00:44 by fwu               #+#    #+#             */
/*   Updated: 2024/02/18 17:58:56 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	size_t			i;
	int				diff;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		diff = cs1[i] - cs2[i];
		if (diff != 0)
		{
			return (diff);
		}
		i++;
	}
	return (0);
}

// int main(void)
// {
// 	char s1[10] = "abc";
// 	char s2[10] = "abc";
// 	printf("memcmp:   [%d]\n", memcmp(s1, s2, 12));
// 	printf("ft_memcmp:[%d]\n", ft_memcmp(s1, s2, 12));
// }
