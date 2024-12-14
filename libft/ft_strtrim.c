/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:53:14 by fwu               #+#    #+#             */
/*   Updated: 2024/01/31 13:53:14 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_cmp(char s, char const *set)
{
	while (*set != '\0')
	{
		if (*set == s)
		{
			return (1);
		}
		set++;
	}
	return (0);
}

static int	get_start_idx(char const *s1, char const *set)
{
	int	idx_s1;

	idx_s1 = 0;
	while (s1[idx_s1] != '\0')
	{
		if (char_cmp(s1[idx_s1], set))
		{
			idx_s1++;
		}
		else
		{
			break ;
		}
	}
	return (idx_s1);
}

static int	get_end_idx(char const *s1, char const *set)
{
	int	s1_len;
	int	idx_s1;

	s1_len = ft_strlen(s1);
	idx_s1 = s1_len;
	while (idx_s1 - 1 >= 0)
	{
		if (char_cmp(s1[idx_s1 - 1], set))
		{
			idx_s1--;
		}
		else
		{
			break ;
		}
	}
	return (idx_s1);
}

static void	trim_word(char const *s1, char *str, int start_idx, int end_idx)
{
	int	i;

	i = start_idx;
	while (i < end_idx)
	{
		*str++ = s1[i++];
	}
	*str = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start_idx;
	int		end_idx;
	int		str_len;

	start_idx = get_start_idx(s1, set);
	end_idx = get_end_idx(s1, set);
	str_len = end_idx - start_idx;
	if (str_len < 0)
	{
		str_len = 0;
	}
	str = malloc(str_len + 1);
	if (!str)
	{
		return (0);
	}
	trim_word(s1, str, start_idx, end_idx);
	return (str);
}

// int main(void)
// {
// 	char *s1 = "";
// 	char *set = "";
// 	printf("[%d]\n", get_start_idx(s1, set));
// 	printf("[%d]\n", get_end_idx(s1, set));
// 	printf("[%s]\n", ft_strtrim(s1, set));
// }