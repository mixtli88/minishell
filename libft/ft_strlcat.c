/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:49:26 by fwu               #+#    #+#             */
/*   Updated: 2024/02/19 14:41:27 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	idx_src;
	size_t	idx_dst;

	idx_dst = 0;
	idx_src = 0;
	while ((idx_dst < size) && (dst[idx_dst] != '\0'))
	{
		idx_dst++;
	}
	while ((idx_src + idx_dst + 1 < size) && (src[idx_src] != '\0'))
	{
		dst[idx_dst + idx_src] = src[idx_src];
		idx_src++;
	}
	if (idx_src > 0)
	{
		dst[idx_dst + idx_src] = '\0';
	}
	return (idx_dst + (size_t)ft_strlen(src));
}

// int main(int ac, char **av)
// {
// 	char dst1[20] = "pqrs";
// 	char src1[20] = "abcdefghi";
// 	size_t	dstsize1; 
// = limit len of final dst = limit len of original dst + src
// 	size_t	len1; 
// = dstsize + len of src, max: max len of original dst + src
// 	dstsize1 = atoi(av[1]);
// 	len1 = strlcat(dst1, src1, dstsize1);
// 	printf("strlcat:      [%zu] dst:[%s] src:[%s]\n", len1, dst1, src1);

// 	char dst2[20] = "pqrs";
// 	char src2[20] = "abcdefghi";
// 	size_t	dstsize2;
// 	size_t	len2;
// 	dstsize2 = atoi(av[1]);
// 	len2 = ft_strlcat(dst2, src2, dstsize2);
// 	printf("ft_strlcat:   [%zu] dst:[%s] src:[%s]\n", len2, dst2, src2);

// 	(void) ac;
// }