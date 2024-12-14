/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:35:40 by fwu               #+#    #+#             */
/*   Updated: 2024/02/18 18:00:07 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	size_t			i;
	int				diff;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = 0;
	while (!((cs1[i] == '\0' && cs2[i] == '\0') || (i == n)))
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
//     char str1[10] = "apple";
//     char str2[10] = "app";
// 	int n1 = 3;
//     int result1 = strncmp(str1, str2, n1);
// 	printf("%s %s %d", str1, str2, result1);

// 	printf("\n");
//     char str3[10] = "apple";
//     char str4[10] = "app";
// 	int n2 = 3;	
//     int result2 = ft_strncmp(str3, str4, n2);
// 	printf("%s %s %d", str3, str4, result2);

// 	return (0);
// }
