/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:10:49 by fwu               #+#    #+#             */
/*   Updated: 2024/02/18 17:57:37 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*tmp_str;

	i = 0;
	tmp_str = s;
	while (i < n)
	{
		tmp_str[i] = '\0';
		i++;
	}
}

// int main(void)
// {
// 	char str_bzero[] = "This is string.h library function";
// 	char str_ft_bzero[] = "This is string.h library function";
// 	bzero(str_bzero, 5);
// 	ft_bzero(str_ft_bzero, 5);
// 	printf("bzero:    %s\n", str_bzero + 5);
// 	printf("ft_bzero: %s", str_ft_bzero + 5);
// }
