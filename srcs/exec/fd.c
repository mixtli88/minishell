/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:21:53 by fwu               #+#    #+#             */
/*   Updated: 2025/01/23 15:18:33 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define PERMISSIONS 0664

static void	set_cmd_num(t_fd **fd, t_minishell	ms)
{
	t_cmd	*cmd;

	(*fd)->cmd_num = 0;
	cmd = ms.data.cmd_list;
	while (cmd)
	{
		(*fd)->cmd_num++;
		cmd = cmd->next;
	}
}

// int pipe[arg->pipe_num][2];
// (*fd)->pipe = pipe;
static bool	create_t_fd(t_fd **fd, t_minishell	ms)
{
	*fd = (t_fd *)ft_calloc(1, sizeof(t_fd));
	if (!*fd)
		return (false);	
	set_cmd_num(fd, ms);
	if ((*fd)->cmd_num > 1)
		(*fd)->pipe_num = (*fd)->cmd_num - 1;
	else
		(*fd)->pipe_num = 0;
	(*fd)->pipe = (int (*)[2])ft_calloc((*fd)->pipe_num, sizeof(int [2]));
	if (!(*fd)->pipe)
		return (false);
	return (true);
}

bool	prepare_t_fd(t_fd **fd, t_minishell	ms)
{
	if (!create_t_fd(fd, ms))
		return (false);
	(*fd)->infile = STDIN_FILENO;
	(*fd)->outfile = STDOUT_FILENO;
	// get_fd_infile(*fd, arg);
	// get_fd_outfile(*fd, arg);
	return (true);
}

void	close_fd(t_fd *fd)
{
	int	i;

	// if (fd->infile != INFILE_NOT_EXIST && fd->infile != FILE_OPEN_ERROR)
	// close(fd->infile);
	// close(fd->outfile);
	i = 0;
	while (i < fd->pipe_num)
	{
		close(fd->pipe[i][READ_PIPE_IDX]);
		close(fd->pipe[i][WRITE_PIPE_IDX]);
		i++;
	}
}

void	free_t_fd(t_fd	**fd)
{
	if (!*fd)
		return ;
	if ((*fd)->pipe)
	{
		free((*fd)->pipe);
		(*fd)->pipe = NULL;
	}
	free(*fd);
	*fd = NULL;
}

// // EACCES: Permission denied
// // ENOENT: No such file or directory
// static void	get_fd_infile(t_fd *fd, t_arg *arg)
// {
// 	char	*file_name;

// 	if (arg->here_doc)
// 		fd->infile = INFILE_NOT_EXIST;
// 	else
// 	{
// 		file_name = arg->argv[0 + PROGRAM];
// 		fd->infile = open(file_name, O_RDONLY);
// 		if (errno == EACCES || errno == ENOENT)
// 		{
// 			fd->infile = open("/dev/null", O_RDONLY);
// 			ft_putstr_fd("pipex: ", STDERR_FILENO);
// 			ft_putstr_fd(file_name, STDERR_FILENO);
// 			if (errno == EACCES)
// 				ft_putendl_fd(": Permission denied", STDERR_FILENO);
// 			else if (errno == ENOENT)
// 				ft_putendl_fd(": No such file or directory", STDERR_FILENO);
// 		}
// 	}
// 	if (fd->infile == FILE_OPEN_ERROR || errno == EACCES || errno == ENOENT)
// 		fd->infile_status = FILE_OPEN_FAIL;
// 	else
// 		fd->infile_status = FILE_OPEN_SUCCESS;
// }

// // EACCES: Permission denied
// // ENOENT: No such file or directory
// static void	get_fd_outfile(t_fd *fd, t_arg *arg)
// {
// 	int		flag;
// 	char	*file_name;

// 	if (arg->here_doc)
// 		flag = O_APPEND;
// 	else
// 		flag = O_TRUNC;
// 	file_name = arg->argv[arg->argc - 1];
// 	fd->outfile = open(file_name, O_WRONLY | O_CREAT | flag, PERMISSIONS);
// 	if (access(file_name, W_OK) != 0 && errno == EACCES)
// 	{
// 		fd->outfile = open("/dev/null", O_WRONLY | flag, PERMISSIONS);
// 		ft_putstr_fd("pipex: ", STDERR_FILENO);
// 		ft_putstr_fd(file_name, STDERR_FILENO);
// 		ft_putendl_fd(": Permission denied", STDERR_FILENO);
// 	}
// 	if (fd->outfile == FILE_OPEN_ERROR
// 		|| (access(file_name, W_OK) != 0 && errno == EACCES))
// 		fd->outfile_status = FILE_OPEN_FAIL;
// 	else
// 		fd->outfile_status = FILE_OPEN_SUCCESS;
// }
