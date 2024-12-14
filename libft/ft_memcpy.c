/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:10:49 by fwu               #+#    #+#             */
/*   Updated: 2024/02/19 14:40:22 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp_dst;
	char	*tmp_src;

	i = 0;
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (!tmp_dst && !tmp_src)
		return (0);
	while (i < n)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	return (tmp_dst);
}

// int main(void)
// {
// 	char src1[] = "abcdefghijklm";
// 	char dst1[] = "ABCDEFGHIJKLM";
// 	char src2[] = "abcdefghijklm";
// 	char dst2[] = "ABCDEFGHIJKLM";
// 	printf("memcpy:    %s\n", memcpy(dst1, src1, 0));
// 	printf("ft_memcpy: %s", ft_memcpy(dst2, src2, 0));
// }