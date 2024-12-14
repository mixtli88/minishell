/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:53:02 by fwu               #+#    #+#             */
/*   Updated: 2024/03/02 10:12:42 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

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

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(count * size);
	if (!ptr)
	{
		return (0);
	}
	i = 0;
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
