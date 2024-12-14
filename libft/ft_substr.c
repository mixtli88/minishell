/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:53:14 by fwu               #+#    #+#             */
/*   Updated: 2024/01/31 13:53:14 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_malloc_len(unsigned int tot_len,
unsigned int start, unsigned int len)
{
	if (start + len >= tot_len)
	{
		if (start >= tot_len)
		{
			return (0 + 1);
		}
		return (tot_len - start + 1);
	}
	return (len + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	tot_len;
	unsigned int	malloc_len;

	tot_len = ft_strlen(s);
	malloc_len = get_malloc_len(tot_len, start, len);
	str = malloc(malloc_len);
	if (!str)
	{
		return (0);
	}
	i = 0;
	while (tot_len > 0 && (unsigned int)len > 0 && start < tot_len
		&& i < (unsigned int)len && s[start + i] != '\0'
		&& start + i < tot_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	*str;

// 	str = ft_substr("hola", 429496, 14);
// 	printf("%s", str);
// }
