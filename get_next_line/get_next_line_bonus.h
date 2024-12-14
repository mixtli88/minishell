/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:27:09 by fwu               #+#    #+#             */
/*   Updated: 2024/03/02 10:20:39 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif // BUFFER_SIZE

typedef struct s_line
{
	char	*str;
	ssize_t	size;
}	t_line;

typedef struct s_buf
{
	char	str[BUFFER_SIZE + 1];
	ssize_t	size;
}	t_buf;

# define ERROR -1
# define FIND_LINE_END 1
# define NON_FIND_LINE_END 0

// get_next_line_bonus.c
char	*get_next_line(int fd);

// get_next_line_utils_bonus.c
void	*ft_memset(void *str, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);

#endif // GET_NEXT_LINE_BONUS_H