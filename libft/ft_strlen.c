/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:00:44 by fwu               #+#    #+#             */
/*   Updated: 2025/01/21 14:08:42 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if(!str)
		return(0);
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return (count);
}

// int main(void)
// {
// 	printf("%d", ft_strlen("ssss"));
// }