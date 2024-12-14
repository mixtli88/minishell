/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:58:46 by fwu               #+#    #+#             */
/*   Updated: 2024/10/06 17:55:21 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_digits(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

// compare unsigned str with the maximum number
static bool	is_in_positive_range(char *unsigned_str)
{
	int	str_len;
	int	max_len;
	int	i;

	while (*unsigned_str == '0' && *(unsigned_str + 1) != '\0')
		unsigned_str++;
	str_len = ft_strlen(unsigned_str);
	max_len = ft_strlen(INT_MAX_STR);
	if (str_len > max_len)
		return (false);
	else if (str_len == max_len)
	{
		i = 0;
		while (i < str_len)
		{
			if (unsigned_str[i] > INT_MAX_STR[i])
				return (false);
			if (unsigned_str[i] < INT_MAX_STR[i])
				break ;
			i++;
		}
	}
	return (true);
}

// compare unsigned str with the minimum number
static bool	is_in_negative_range(char *unsigned_str)
{
	int	str_len;
	int	min_len;
	int	i;

	while (*unsigned_str == '0' && *(unsigned_str + 1) != '\0')
		unsigned_str++;
	str_len = ft_strlen(unsigned_str);
	min_len = ft_strlen(INT_MIN_STR) - 1;
	if (str_len > min_len)
		return (false);
	else if (str_len == min_len)
	{
		i = 0;
		while (i < str_len)
		{
			if (unsigned_str[i] > INT_MIN_STR[i + 1])
				return (false);
			if (unsigned_str[i] < INT_MIN_STR[i + 1])
				break ;
			i++;
		}
	}
	return (true);
}

bool	ft_isint(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (!is_digits(str))
		return (false);
	if (*str == '-')
	{
		str++;
		return (is_in_negative_range(str));
	}
	else
	{
		if (*str == '+')
			str++;
		return (is_in_positive_range(str));
	}
}
