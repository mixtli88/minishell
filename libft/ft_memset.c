/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:10:49 by fwu               #+#    #+#             */
/*   Updated: 2024/02/18 17:59:10 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*tmp_str;

	i = 0;
	tmp_str = str;
	while (i < n)
	{
		tmp_str[i] = c;
		i++;
	}
	return (tmp_str);
}

// int main(void)
// {
// 	char str[] = "This is string.h library function";
// 	printf("memset:    %s\n", memset(str, '$', 0));
// 	printf("ft_memset: %s", ft_memset(str, '$', 0));
// }