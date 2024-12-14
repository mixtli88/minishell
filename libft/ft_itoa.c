/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:13:00 by fwu               #+#    #+#             */
/*   Updated: 2024/02/19 20:02:38 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	transform(char *str, long n, int digits)
{
	int	i;

	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	i = digits - 1;
	while (1)
	{
		if (n / 10 <= 0)
		{
			str[i] = n + '0';
			i--;
			break ;
		}
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	str[digits] = '\0';
}

static int	get_digits(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (1)
	{
		if (n / 10 <= 0)
		{
			count++;
			break ;
		}
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;

	digits = get_digits(n);
	str = (char *)malloc(digits * sizeof(char) + 1);
	if (!str)
	{
		return (0);
	}
	transform(str, n, digits);
	return (str);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(-2147483647));
// }
