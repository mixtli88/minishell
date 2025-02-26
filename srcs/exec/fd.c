/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:21:53 by fwu               #+#    #+#             */
/*   Updated: 2025/02/26 08:00:57 by mike             ###   ########.fr       */
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

void	fd_and_pipe(t_minishell	*ms)
{
	int	i;

	i = 0;
	ms->fd.cmd_num = ms->data.count_cmd;
	ms->fd.pipe_num = ms->fd.cmd_num  - 1;
	ms->fd.infile = STDIN_FILENO;
	ms->fd.outfile = STDOUT_FILENO;
	if(ms->data.count_cmd > 1)
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

void	get_rdir_for_fd(t_minishell	*ms, t_cmd *cmd)
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
			ms->fd.infile = creat_tem_heredoc(tem->fd_rdir);
		else if (tem->type == DOUBLE_OUT)
			ms->fd.outfile = open(tem->fd_rdir, O_WRONLY | O_CREAT | O_APPEND, PERMISSIONS);
		if (ms->fd.infile  == -1 || ms->fd.outfile == -1 )
			error_open_file(ms, tem->fd_rdir);
		if(ms->data.flag == -1)
			break;
		tem = tem->next;
	}
}

void	 get_fd_exe(t_minishell	*ms, t_cmd *cmd)
{	
	ms->exe.infd = ms->fd.infile;
	ms->exe.outfd = ms->fd.outfile;
	if (cmd->id == 1)
	{
		if (ms->fd.cmd_num != 1 )
			if(ms->fd.outfile == STDOUT_FILENO)
				ms->exe.outfd =ms->fd.pipe[0][WRITE_PIPE_IDX];
	}
	else if (cmd->id  == ms->fd.cmd_num)
	{
		if(ms->fd.infile == STDIN_FILENO)
			ms->exe.infd = ms->fd.pipe[ms->fd.cmd_num - 2][READ_PIPE_IDX];
	}
	else
	{
		if(ms->fd.infile == STDIN_FILENO)
			ms->exe.infd = ms->fd.pipe[cmd->id - 2][READ_PIPE_IDX];
		if(ms->fd.outfile == STDOUT_FILENO)
			ms->exe.outfd = ms->fd.pipe[cmd->id - 1][WRITE_PIPE_IDX];
	}	
}
