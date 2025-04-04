/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:53:51 by fwu               #+#    #+#             */
/*   Updated: 2025/03/13 09:37:29 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    count_words(char const *str, int c)
{
    int    count;
    int    i;

    count = 0;
    i = 0;
    while (str[i])
    {
        while (str[i] == c)
            i++;
        if (str[i])
            count++;
        while (str[i] && str[i] != c)
            i++;
    }
    return (count);
}

char    **ft_split(char const *str, char c)
{
    int        i;
    int        j;
    int        k;
    int        word_count;
    char    **result;

    word_count = count_words(str, c);
    result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!result)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i])
    {
        while (str[i] == c)
            i++;
        if (str[i])
        {
            k = 0;
            while (str[i + k] && str[i + k] != c)
                k++;
            result[j] = (char *)malloc(sizeof(char) * (k + 1));
            if (!result[j])
                return (NULL);
            k = 0;
            while (str[i] && str[i] != c)
                result[j][k++] = str[i++];
            result[j][k] = '\0';
            j++;
        }
    }
    result[j] = NULL;
    return (result);
}

// static int	count_words(char const *str, char c)
// {
// 	int	count;
// 	int	new_word;

// 	count = 0;
// 	new_word = 1;
// 	while (*str != '\0')
// 	{
// 		if (*str == c)
// 		{
// 			new_word = 1;
// 		}
// 		else if (new_word == 1
// 			&& (!(*str == c)))
// 		{
// 			count++;
// 			new_word = 0;
// 		}
// 		str++;
// 	}
// 	return (count);
// }

// static char	*get_word(char const *str, int tot_len, int s_idx, int e_idx)
// {
// 	char	*string;
// 	int		word_len;
// 	int		i;

// 	string = 0;
// 	if (s_idx > e_idx || s_idx >= tot_len || e_idx > tot_len)
// 	{
// 		return (string);
// 	}
// 	word_len = e_idx - s_idx;
// 	string = malloc(sizeof(char) * (word_len + 1));
// 	if (!string)
// 	{
// 		return (0);
// 	}
// 	i = 0;
// 	while (i < word_len)
// 	{
// 		string[i++] = str[s_idx++];
// 	}
// 	string[i] = '\0';
// 	return (string);
// }

// static void	split_word(char **str2, char const *str, char c, int s_idx)
// {
// 	int	cur_idx;
		
// 	cur_idx = 0;
// 	while (str[cur_idx] != '\0')
// 	{
// 		if (str[cur_idx] == c)
// 		{
// 			if (s_idx != -1)
// 			{
// 				*str2++ = get_word(str, ft_strlen(str), s_idx, cur_idx);
// 			}
// 			s_idx = -1;
// 		}		
// 		if (s_idx == -1 && (str[cur_idx] != c))
// 		{
// 			s_idx = cur_idx;
// 		}
// 		cur_idx++;
// 	}
// 	if (s_idx != -1)
// 		*str2++ = get_word(str, ft_strlen(str), s_idx, cur_idx);
// 	*str2 = 0;
// }

// char	**ft_split(char const *str, char c)
// {
// 	char	**str2;
// 	int		s_idx;

// 	if (str == NULL)
// 		return (0);
// 	str2 = (char **) malloc(sizeof(char *) * (count_words(str, c) + 1));
// 	if (!str2)
// 		return (0);
// 	s_idx = -1;
// 	split_word(str2, str, c, s_idx);
// 	return (str2);
// }

// // int main()
// // {
// // 	char *str1 = "5--a-accd-d-";
// // 	char **str2 = ft_split(str1, '-');

// // 	while (*str2 != 0)
// // 	{
// // 		printf("%s\n", *str2);
// // 		str2++;
// // 	}
// // }
