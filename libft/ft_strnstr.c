/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:40 by fwu               #+#    #+#             */
/*   Updated: 2024/02/18 17:57:13 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx_haystack;
	size_t	idx_needle;	

	idx_haystack = 0;
	if (needle == 0 || needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && idx_haystack < len)
	{
		idx_needle = 0;
		while (needle[idx_needle] != '\0' && idx_haystack + idx_needle < len)
		{
			if (haystack[idx_needle] != needle[idx_needle])
				break ;
			idx_needle++;
			if (needle[idx_needle] == '\0')
				return ((char *)haystack);
		}
		idx_haystack++;
		haystack++;
	}
	return (0);
}

// int main(void)
// {
// 	char haystack1[10] = "abc";	
// 	char needle1[10] = "";
// 	printf("strnstr:   [%s]\n",    strnstr(haystack1, needle1, 5));
// 	char haystack2[10] = "abc";	
// 	char needle2[10] = "";
// 	printf("ft_strnstr:[%s]\n", ft_strnstr(haystack2, needle2, 5));
// }
