/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                   	                              +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:53:14 by fwu               #+#    #+#             */
/*   Updated: 2024/01/31 13:53:14 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	toupper(unsigned int idx, char *str)
// {
// 	str[idx] -= 32;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

// int main(void)
// {
// 	char str[] = "abcdefg";
// 	ft_striteri(str, &toupper);
// 	printf("%s", str);
// }