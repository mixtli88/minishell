/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:00:44 by fwu               #+#    #+#             */
/*   Updated: 2024/02/18 17:57:21 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*d;

	d = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			d = (char *)s;
		}
		s++;
	}
	if ((char)c == '\0')
		d = (char *)s;
	return (d);
}

// int main(void)
// {
// 	char s1[7] = "abcabc";
// 	char s2[7] = "abcabc";
// 	printf("strrchr:   [%s]\n", strrchr(s1, 'c'));
// 	printf("ft_strrchr:[%s]\n", ft_strrchr(s2, 'c'));
// }
