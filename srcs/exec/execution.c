/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:53:25 by fwu               #+#    #+#             */
/*   Updated: 2025/02/06 04:42:31 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fd_and_pipe(t_minishell	*ms)
{
	int	i;

	i = 0;
	ms->fd.cmd_num = ms->data.count_cmd;
	ms->fd.pipe_num = ms->fd.cmd_num  - 1;
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

void fork_cmd(t_minishell	*ms, t_cmd *cmd)
{
	int	status;
	int	id;
	
	id = fork();
	if (id == -1)
		perror_cmd("fork");
	if (id == 0)
	{
		if (dup2(ms->exe.infd, STDIN_FILENO) == -1)
			perror_cmd("dup2 (infd)");
		if (dup2(ms->exe.outfd, STDOUT_FILENO) == -1)
			perror_cmd("dup2 (outfd)");
		close_fd(ms, cmd);
		if (execve(ms->exe.path, ms->exe.argv, *(ms->exe.envp)) == -1)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(ms->exe.argv[0], STDERR_FILENO);
			ft_putendl_fd(": command not found", STDERR_FILENO); 
			exit(127);
		}
	}
	else
		waitpid(id, &status, 0); 
}

bool	exe_cmd(t_minishell	*ms, t_cmd *cmd)
{	
	if (is_builtin(ms))
		builtin(ms, cmd);
	else
		fork_cmd(ms, cmd);
	if (ms->exe.outfd != STDOUT_FILENO)
		close(ms->exe.outfd);
	if (ms->exe.infd != STDIN_FILENO)
		close(ms->exe.infd);
	return (true);
}

void	execution(t_minishell	*ms)
{
	t_cmd	*cmd;

	cmd = ms->data.cmd_list;
	fd_and_pipe(ms);
	while (cmd)
	{ 
		get_fd_for_cmd(ms, cmd);
		prepare_t_exe(ms, cmd);
		exe_cmd(ms, cmd);
		reset_t_exe(ms);
		reset_t_var(ms);
		cmd = cmd->next;
	}
}