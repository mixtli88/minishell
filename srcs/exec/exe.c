/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:06:19 by fwu               #+#    #+#             */
/*   Updated: 2025/01/30 16:13:06 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char *find_path_exe(t_minishell *ms)
{
	int		i;
	char	**paths;
	char	*full_path;
	char	*tem;
	i  = -1;
	tem = ft_getenv("PATH", *(ms->envp));
	paths = ft_split(tem, ':');
	free(tem);
	while (paths[++i])
	{
		tem = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tem, ms->exe.name);
		if (access(full_path, X_OK) == 0)
		{
			free_table(paths);
			free(tem);
			return(full_path);
		}
		free(tem);
		free(full_path);
	}
	free_table(paths);
	return (NULL);
}


static void	get_fd_exe(t_minishell	*ms, t_cmd *cmd)
{
	if (cmd->id == 1)
	{
	
		ms->exe.infd = ms->fd.infile;
		if (ms->fd.cmd_num == 1)
			ms->exe.outfd = ms->fd.outfile;
		else
			ms->exe.outfd =ms->fd.pipe[0][WRITE_PIPE_IDX];
	}
	else if (cmd->id  == ms->fd.cmd_num)
	{
		ms->exe.infd = ms->fd.pipe[ms->fd.pipe_num - 1][READ_PIPE_IDX];
		ms->exe.outfd = ms->fd.outfile;
	}
	else
	{
		ms->exe.infd = ms->fd.pipe[cmd->id - 1][READ_PIPE_IDX];
		ms->exe.outfd = ms->fd.pipe[cmd->id][WRITE_PIPE_IDX];
	}
}

void	prepare_t_exe(t_minishell *ms, t_cmd *cmd)
{
	if(cmd->argv && cmd->argv[0])
	{
		ms->exe.name = ft_strdup(cmd->argv[0]);
		ms->exe.path = find_path_exe(ms);
	}
	ms->exe.argv = cmd->argv;
	ms->exe.envp = ms->envp;
	get_fd_exe(ms, cmd);
}

void	reset_t_exe(t_minishell *ms)
{
	ms->exe.infd = 0;
	ms->exe.outfd = 0;
	if (ms->exe.name)
		free(ms->exe.name);
	ms->exe.name = NULL;
	if (ms->exe.path)
		free(ms->exe.path);
	ms->exe.path = NULL;
	ms->exe.argv = NULL;
	ms->exe.envp = NULL;
	
}



// static char	**get_exe_argv(char *arg)
// {
// 	return (ft_split(arg, ' '));
// }

// static int	get_exe_arg(int cur_cmd_idx, t_exe *exe, t_arg *arg)
// {
// 	int		arg_cmd_idx;
// 	char	*cmd;

// 	if (arg->here_doc)
// 		arg_cmd_idx = PROGRAM + arg->here_doc + LIMITER + cur_cmd_idx;
// 	else
// 		arg_cmd_idx = PROGRAM + arg->here_doc + INFILE + cur_cmd_idx;
// 	cmd = arg->argv[arg_cmd_idx];
// 	exe->argv = get_exe_argv(cmd);
// 	if (!exe->argv)
// 		return (FAIL);
// 	exe->name = exe->argv[0];
// 	exe->path = get_exe_path(arg->env_path, exe->name);
// 	if (!exe->path)
// 		return (FAIL);
// 	exe->envp = arg->envp;
// 	return (SUCCESS);
// }

