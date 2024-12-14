/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:10:49 by fwu               #+#    #+#             */
/*   Updated: 2024/02/18 18:08:55 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		dist;
	char	*tmp_dst;
	char	*tmp_src;

	i = 0;
	dist = dst - src;
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (!tmp_dst && !tmp_src)
		return (0);
	while (i < len)
	{
		if (dist > 0)
		{
			tmp_dst[len - 1 - i] = tmp_src[len - 1 - i];
		}
		else
		{
			tmp_dst[i] = tmp_src[i];
		}
		i++;
	}
	return (tmp_dst);
}

// int main(void)
// {
// 	char src1[] = "abcdefghijklm";
// 	char dst1[] = "nopqrstuvwxyz";
// 	char src2[] = "abcdefghijklm";
// 	char dst2[] = "nopqrstuvwxyz";	
// 	printf("memmove:   [%s] src:[%s] dst:[%s]\n", 
//memmove(src1 + 1, src1, 5), src1, src1 + 1);
// 	printf("ft_memmove:[%s] src:[%s] dst:[%s]\n", 
//ft_memmove(src2 + 1, src2, 5), src2, src2 + 1);
// 	printf("memmove:   [%s] src:[%s] dst:[%s]\n", 
//memmove(dst1, src1, 5), src1, dst1);
// 	printf("ft_memmove:[%s] src:[%s] dst:[%s]\n", 
//ft_memmove(dst2, src2, 5), src2, dst2);
// }