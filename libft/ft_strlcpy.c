/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:00:44 by fwu               #+#    #+#             */
/*   Updated: 2024/02/19 14:41:39 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < dstsize - 1 && dstsize > 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
	{
		dst[i] = '\0';
	}
	return ((size_t)ft_strlen(src));
}

// int main(void)
// {
// 	char src1[10] = "abc";
// 	char dst1[10] = "ss";
// 	char src2[10] = "abc";
// 	char dst2[10] = "ss";
// 	printf("strlcpy:   [%zu] src:[%s] dst:[%s]\n", 
// 	strlcpy(dst1, src1, sizeof(dst1)), src1, dst1);
// 	printf("ft_strlcpy:[%zu] src:[%s] dst:[%s]\n", 
// 	ft_strlcpy(dst2, src2, sizeof(dst2)), src2, dst2);
// }
