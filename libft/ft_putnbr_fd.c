/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 23:13:00 by fwu               #+#    #+#             */
/*   Updated: 2024/02/19 18:58:02 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_min_int(int nb, int fd)
{
	char	*str;
	int		result;

	str = 0;
	result = 0;
	if (nb == -2147483648)
	{
		str = "-2147483648";
		result = 1;
		while (*str != '\0')
			write(fd, str++, 1);
	}
	return (result);
}

static int	transform(char *str, int value)
{
	int	i;

	i = 0;
	while (1)
	{
		if (value / 10 <= 0)
		{
			str[i] = value + '0';
			i++;
			break ;
		}
		str[i] = value % 10 + '0';
		value /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[15];
	int		i;
	int		value;

	if (check_min_int(n, fd))
		return ;
	i = 0;
	while (i < 15)
	{
		str[i] = '\0';
		i++;
	}
	if (n < 0)
		value = -1 * n;
	else
		value = n;
	i = transform(str, value);
	if (n < 0)
		str[i++] = '-';
	while (i > 0)
		write(fd, &str[--i], 1);
}

// int	main(void)
// {
// 	ft_putnbr_fd(-2147483647, 1);
// }
