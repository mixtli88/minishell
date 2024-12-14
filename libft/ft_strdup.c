/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:46:08 by fwu               #+#    #+#             */
/*   Updated: 2024/02/18 18:00:41 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		total;
	char	*dest;
	int		i;

	total = ft_strlen(s1);
	dest = malloc(sizeof(char) * (total + 1));
	if (!dest)
		return (0);
	i = 0;
	while (i < total)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int main(void)
// {
	// char *src;
	// char *dest;
	// char *ft_dest;
	// src = "abc";
	// dest = strdup(src);
	// ft_dest = ft_strdup(src);

	// printf("%p\n", src);
	// printf("%p\n", dest);
	// printf("%p\n", ft_dest);

	// printf("src:     [%s]\n", src);
	// printf("dest:    [%s]\n", dest);
	// printf("ft_dest: [%s]\n", ft_dest);

	// free(dest);
	// free(ft_dest);	
// }
