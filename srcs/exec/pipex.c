/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:53:25 by fwu               #+#    #+#             */
/*   Updated: 2025/01/30 16:16:07 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pipe_fd(t_minishell	*ms)
{
	int	i;

	i = 0;
	ms->fd.pipe = malloc(sizeof(int *) * (ms->fd.pipe_num));
	while (i < ms->fd.pipe_num)
	{
		ms->fd.pipe[i] = malloc(sizeof(int) * 2);
		if (pipe(ms->fd.pipe[i]) == -1)
		{
			perror("pipe error");
			exit(EXIT_FAILURE);
	    }
		i++;
	}
}


// mike
bool	pipex(t_minishell	*ms)
{
	t_cmd	*cmd;

	cmd = ms->data.cmd_list;
	if (ms->data.cmd_list)
	{
		prepare_t_fd(ms, cmd);
		if(ms->data.count > 1)
			pipe_fd(ms);
		if (!fork_and_execute(ms, cmd))
		{
			free_t_fd(ms);
			return (false);
		}
		return (true);
	}
	return (false);
}




// bool	pipex(t_minishell	*ms) // fan
// {
// 	t_fd	*fd;

// 	if (!prepare_t_fd(&fd, ms))
// 	{
// 		free_t_fd(&fd);
// 		return (false);
// 	}
// 	if (!pipe_fd(fd))
// 	{
// 		free_t_fd(&fd);
// 		return (false);
// 	}
// 	get_input_from_here_doc(fd, arg);
// 	if (!fork_and_execute(fd, ms))
// 	{
// 		free_t_fd(&fd);
// 		return (false);
// 	}
// 	free_t_fd(&fd);
// 	return (true);
// }

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

