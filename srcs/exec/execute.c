/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:45:51 by fwu               #+#    #+#             */
/*   Updated: 2025/01/23 19:19:44 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	execute_exe(t_exe *exe, t_fd *fd)
{
	if (dup2(exe->infd, STDIN_FILENO) == -1)
		return (false);
	if (dup2(exe->outfd, STDOUT_FILENO) == -1)
		return (false);
	close_fd(fd);
	if (is_builtin(exe))
		builtin(exe);
	if (execve(exe->path, exe->argv, *(exe->envp)) == -1)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(exe->name, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		return (false);
	}
	// if (ft_strncmp(str, "", 1) == 0)
	// 	error_path_cmd(cmd);
	// if (ft_strncmp(str, "/", 1) == 0)
	// 	error_directory(ms);
	// if (ft_strncmp(str, "!", 1) == 0)
	// 	error_syntax(ms);
	// if (ft_strncmp(str, ":", 1) == 0)
	// 	ft_minishell_loop(ms);	
	return (true);
}

static int	execute_cmd(t_fd *fd, t_cmd	*cmd, char ***envp)
{
	t_exe	*exe;

	if (!prepare_t_exe(fd, cmd, envp, &exe))
	{
		free_t_exe(&exe);
		return (false);
	}
	if (!execute_exe(exe, fd))
	{
		free_t_exe(&exe);
		return (false);
	}
	free_t_exe(&exe);
	return (true);
}

bool	fork_and_execute(t_fd *fd, t_minishell	*ms)
{
	int	id;
	int	status;
	t_cmd	*cmd;

	cmd = ms->data.cmd_list;
	while (cmd && cmd->argv[0])
	{
		id = fork();
		if (id == -1)
			return (false);
		if (id == 0)
		{
			// if (check_execute(i, arg->cmd_num, fd) == FAIL)
			// 	return (FAIL);
			if (!execute_cmd(fd, cmd, ms->envp))
				return (false);
		}
		waitpid(id, &status, WNOHANG);
		cmd = cmd->next;
	}
	close_fd(fd);
	return (true);
}

// static int	check_execute(int cur_cmd_idx, int cmd_num, t_fd *fd)
// {
// 	if (cur_cmd_idx == 0 && fd->infile_status)
// 		return (FAIL);
// 	else if (cur_cmd_idx == cmd_num - 1 && fd->outfile_status)
// 		return (FAIL);
// 	return (SUCCESS);
// }