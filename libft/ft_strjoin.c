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

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	int		i;

// 	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!s1)
// 		return (0);
// 	if (!str)
// 		return (0);
// 	if (!s2)
// 		return (0);
// 	i = 0;
// 	while (*s1 != '\0')
// 		str[i++] = *s1++;
// 	while (*s2 != '\0')
// 		str[i++] = *s2++;
// 	str[i] = '\0';
// 	return (str);
// }
char	*ft_strjoinfree(char  *s1, char  *s2)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	if (!s1)
		return (0);
	if (!s2)
		return (0);
	i = 0;
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (str);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2) 
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0') // No modificar s1 directamente
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0') // No modificar s2 directamente
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}