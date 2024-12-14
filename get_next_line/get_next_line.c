/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:53:21 by fwu               #+#    #+#             */
/*   Updated: 2024/03/02 21:51:13 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buf	*read_stash_to_buf(int fd, char *stash[])
{
	t_buf	*tbuf;

	tbuf = (t_buf *)ft_calloc(1, sizeof(t_buf));
	if (!tbuf)
		return (0);
	if (!stash[fd])
	{
		tbuf->size = 0;
	}
	else
	{
		tbuf->size = ft_strlen(stash[fd]);
		ft_memcpy(tbuf->str, stash[fd], tbuf->size);
		free(stash[fd]);
		stash[fd] = 0;
	}
	return (tbuf);
}

static void	str_add_char(t_line *line, char c)
{
	char	*str_tmp;
	ssize_t	str_tmp_len;

	str_tmp = 0;
	str_tmp_len = line->size + 1;
	str_tmp = (char *)ft_calloc(str_tmp_len + 1, sizeof(char));
	if (!str_tmp)
	{
		if (line->size > 0)
		{
			free(line->str);
			line->str = 0;
		}
		return ;
	}
	if (line->size > 0)
	{
		ft_memcpy(str_tmp, line->str, line->size);
		free(line->str);
	}
	str_tmp[(line->size)++] = c;
	line->str = str_tmp;
}

static int	parse_and_clean_buf(int fd, t_line *line, t_buf *buf, char *stash[])
{
	int	idx_buf;

	idx_buf = 0;
	while (idx_buf < buf->size)
	{
		str_add_char(line, buf->str[idx_buf]);
		if (!(line->str))
			return (ERROR);
		if (buf->str[idx_buf++] == '\n')
		{
			if (buf->str[idx_buf] != '\0')
			{
				stash[fd] = ft_strdup(&(buf->str[idx_buf]));
				if (!stash[fd])
					return (ERROR);
			}
			return (FIND_LINE_END);
		}
	}
	ft_memset(buf->str, '\0', BUFFER_SIZE + 1);
	buf->size = 0;
	return (NON_FIND_LINE_END);
}

static void	read_file_to_buf(int fd, t_line *line, t_buf *buf, char *stash[])
{
	int	parse_result;

	while (1)
	{
		if (buf->size == 0)
		{
			ft_memset(buf->str, '\0', BUFFER_SIZE + 1);
			buf->size = read(fd, buf->str, BUFFER_SIZE);
			if (buf->size == -1)
			{
				free(line->str);
				line->str = 0;
			}
		}
		if (buf->size > 0)
		{
			parse_result = parse_and_clean_buf(fd, line, buf, stash);
			if ((parse_result == ERROR) || (parse_result == FIND_LINE_END))
				return ;
		}
		else
			return ;
	}
}

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	t_line		*line;
	t_buf		*buf;
	char		*str;

	if (fd < 0)
		return (0);
	line = (t_line *)ft_calloc(1, sizeof(t_line));
	if (!line)
		return (0);
	line->str = 0;
	line->size = 0;
	buf = read_stash_to_buf(fd, stash);
	if (!buf)
		return (0);
	read_file_to_buf(fd, line, buf, stash);
	str = line->str;
	free(line);
	free(buf);
	return (str);
}
