/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:53:25 by fwu               #+#    #+#             */
/*   Updated: 2025/01/23 15:15:30 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	pipe_fd(t_fd *fd)
{
	int	i;

	i = 0;
	while (i < fd->pipe_num)
	{
		if (pipe(fd->pipe[i]) == -1)
			return (false);
		i++;
	}
	return (true);
}

bool	pipex(t_minishell	*ms)
{
	t_fd	*fd;

	if (!prepare_t_fd(&fd, *ms))
	{
		free_t_fd(&fd);
		return (false);
	}
	if (!pipe_fd(fd))
	{
		free_t_fd(&fd);
		return (false);
	}
	// get_input_from_here_doc(fd, arg);
	if (!fork_and_execute(fd, ms))
	{
		free_t_fd(&fd);
		return (false);
	}
	free_t_fd(&fd);
	return (true);
}




// static int	check_diff(char	*limiter, char *newline)
// {
// 	int	len_limiter;
// 	int	len_newline;
// 	int	len_cmp;

// 	len_limiter = ft_strlen(limiter);
// 	len_newline = ft_strlen(newline) - 1;
// 	if (len_limiter > len_newline)
// 		len_cmp = len_limiter;
// 	else
// 		len_cmp = len_newline;
// 	if (ft_strncmp(limiter, newline, len_cmp) != 0)
// 		return (FAIL);
// 	return (SUCCESS);
// }

// static void	get_input_from_here_doc(t_fd *fd, t_arg *arg)
// {
// 	char	*limiter;
// 	char	*newline;

// 	if (arg->here_doc)
// 	{
// 		limiter = arg->argv[0 + PROGRAM + arg->here_doc];
// 		ft_putstr_fd("> ", STDOUT_FILENO);
// 		newline = get_next_line(STDIN_FILENO);
// 		while (newline != NULL && check_diff(limiter, newline) == FAIL)
// 		{
// 			ft_putstr_fd(newline, fd->pipe[INI_PIPE_IDX][WRITE_PIPE_IDX]);
// 			if (newline != NULL)
// 				free(newline);
// 			ft_putstr_fd("> ", STDOUT_FILENO);
// 			newline = get_next_line(STDIN_FILENO);
// 		}
// 		if (newline != NULL)
// 			free(newline);
// 	}
// }

