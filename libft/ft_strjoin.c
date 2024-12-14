/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:53:14 by fwu               #+#    #+#             */
/*   Updated: 2024/01/31 13:53:14 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
	{
		return (0);
	}
	i = 0;
	while (*s1 != '\0')
	{
		str[i++] = *s1++;
	}
	while (*s2 != '\0')
	{
		str[i++] = *s2++;
	}
	str[i] = '\0';
	return (str);
}
