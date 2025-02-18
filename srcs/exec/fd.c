/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:21:53 by fwu               #+#    #+#             */
/*   Updated: 2025/02/14 09:47:28 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#define PERMISSIONS 0664

void rdir_fd(t_minishell *ms, t_cmd *cmd)
{
	if (cmd->rdir->type == SINGLE_IN)
		ms->fd.infile = open(cmd->rdir->fd_rdir, O_RDONLY, PERMISSIONS);
	else if (cmd->rdir->type == SINGLE_OUT)
		ms->fd.outfile= open(cmd->rdir->fd_rdir, O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
	else if (cmd->rdir->type == DOUBLE_IN)
		ms->fd.infile = open(cmd->rdir->fd_rdir, O_RDONLY, PERMISSIONS);
	else if (cmd->rdir->type == DOUBLE_OUT)
		ms->fd.outfile = open(cmd->rdir->fd_rdir, O_WRONLY | O_CREAT | O_APPEND, PERMISSIONS);
	if (ms->fd.infile  == -1 || ms->fd.outfile == -1 )
		error_open_file(ms, cmd->rdir->fd_rdir);
	
}
void error_open_file(t_minishell *ms,   char *file)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putendl_fd(": No such file or directory", STDERR_FILENO);
	ms->status = 1;
	ms->data.flag = -1;
}

// void	get_fd_for_cmd(t_minishell	*ms, t_cmd *cmd)
// {
// 	while(cmd->rdir)
// 	{
		
// 		if (cmd->rdir->type == SINGLE_IN)
// 		ms->fd.infile = open(cmd->rdir->fd_rdir, O_RDONLY, PERMISSIONS);
// 		else if (cmd->rdir->type == SINGLE_OUT)
// 			ms->fd.outfile= open(cmd->rdir->fd_rdir, O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
// 		else if (cmd->rdir->type == DOUBLE_IN)
// 			ms->fd.infile = open(cmd->rdir->fd_rdir, O_RDONLY, PERMISSIONS);
// 		else if (cmd->rdir->type == DOUBLE_OUT)
// 			ms->fd.outfile = open(cmd->rdir->fd_rdir, O_WRONLY | O_CREAT | O_APPEND, PERMISSIONS);
// 		if (ms->fd.infile  == -1 || ms->fd.outfile == -1 )
// 			error_open_file(cmd->rdir->fd_rdir);
// 		cmd->rdir = cmd->rdir->next;
// 	}
// }

void	get_fd_for_cmd(t_minishell	*ms, t_cmd *cmd)
{
	t_rdir *tem;
	
	tem = cmd->rdir;
	while(tem)
	{
		if (tem->type == SINGLE_IN)
		ms->fd.infile = open(tem ->fd_rdir, O_RDONLY, PERMISSIONS);
		else if (tem->type == SINGLE_OUT)
			ms->fd.outfile= open(tem->fd_rdir, O_WRONLY | O_CREAT | O_TRUNC, PERMISSIONS);
		else if (tem->type == DOUBLE_IN)
			ms->fd.infile = open(tem->fd_rdir, O_RDONLY, PERMISSIONS);
		else if (tem->type == DOUBLE_OUT)
			ms->fd.outfile = open(tem->fd_rdir, O_WRONLY | O_CREAT | O_APPEND, PERMISSIONS);
		if (ms->fd.infile  == -1 || ms->fd.outfile == -1 )
			error_open_file(ms, tem->fd_rdir);
		if(ms->data.flag == -1)
			break;
		tem = tem->next;
	}
}


// void	get_fd_for_cmd(t_minishell	*ms, t_cmd *cmd)
// {
// 	if(cmd->rdir->type == SINGLE_IN || cmd->rdir->type == DOUBLE_IN)
// 	{
// 		rdir_fd(ms, cmd);
// 		ms->fd.outfile = STDOUT_FILENO;
// 	}
// 	else if(cmd->rdir->type == SINGLE_OUT || cmd->rdir->type == DOUBLE_OUT)
// 	{
// 		rdir_fd(ms, cmd);
// 		ms->fd.infile = STDIN_FILENO;
// 	}
// 	else
// 	{
// 		ms->fd.infile = STDIN_FILENO;
// 		ms->fd.outfile = STDOUT_FILENO;
// 	}	
// }

void	close_fd(t_minishell	*ms, t_cmd *cmd)
{
	int i;

	i = 0;
	while(i < ms->fd.pipe_num)
	{
		if(i != cmd->id - 1)
			close(ms->fd.pipe[i][READ_PIPE_IDX]);
		if(i != cmd->id)
			close(ms->fd.pipe[i][WRITE_PIPE_IDX]);
		i++;	
	}
}

void	free_t_fd(t_minishell	*ms)
{
	int	i;
	
	i = 0;
	ms->fd.infile = STDIN_FILENO;
	ms->fd.outfile = STDOUT_FILENO;
	ms->fd.pipe_num = 0;	// cantidad de pipes
	ms->fd.cmd_num = 0; 			// cantidad de comandos
	if (ms->fd.pipe)
	{
		while (i < ms->fd.pipe_num)
		{
			free(ms->fd.pipe[i]);
			i++;
		}
		free(ms->fd.pipe);
		ms->fd.pipe = NULL;
	}
}
