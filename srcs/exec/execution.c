/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:53:25 by fwu               #+#    #+#             */
/*   Updated: 2025/03/24 11:26:54 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void fork_cmd(t_minishell *ms, t_cmd *cmd)
{
    int status;
    
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGINT, handle_signal_son);
    signal(SIGQUIT, handle_signal_son);
    ms->exe.id = fork();
    if (ms->exe.id == -1)
        perror_cmd("fork");
    if (ms->exe.id == 0) 
    {
        if (is_builtin(ms))
        {
			builtin(ms, cmd);
            exit(0);
        }
        else 
			proces_execve(ms);
    }
    else 
    {		
        wait(&status);
        if ((status & 0x7F) == 0)
			ms->status = (status >> 8); 
        else
			ms->status = 128 + (status & 0x7F);
    }
}

void	exe_cmd(t_minishell	*ms, t_cmd *cmd)
{	
	if (is_builtin(ms) && ms->fd.pipe_num == 0)
		builtin(ms, cmd);
	else
		fork_cmd(ms, cmd);
	close_fd_exe(ms);
}

void	execution(t_minishell	*ms)
{
	t_cmd	*cmd;

	cmd = ms->data.cmd_list;
	fd_and_pipe(ms);
	while (cmd)
	{ 
		get_rdir_for_fd(ms, cmd);
		prepare_t_exe(ms, cmd);
		if(ms->data.flag != -1 && ms->exe.argv)
			exe_cmd(ms, cmd);
		reset_t_exe(ms);
		reset_t_var(ms);
		cmd = cmd->next;
	}
}
