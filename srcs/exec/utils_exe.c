/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:06:19 by fwu               #+#    #+#             */
/*   Updated: 2025/02/13 21:46:27 by mike             ###   ########.fr       */
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


static void	 get_fd_exe(t_minishell	*ms, t_cmd *cmd)
{	
	ms->exe.infd = ms->fd.infile;
	ms->exe.outfd = ms->fd.outfile;
	if (cmd->id == 1)
	{
		if (ms->fd.cmd_num != 1 )
			if(ms->fd.outfile == STDOUT_FILENO)
			{
				ms->exe.outfd =ms->fd.pipe[0][WRITE_PIPE_IDX];
				// ms->data.pipe_use = true;
			}
	}
	else if (cmd->id  == ms->fd.cmd_num)
	{
		if(ms->fd.infile == STDIN_FILENO)
			ms->exe.infd = ms->fd.pipe[ms->fd.cmd_num - 2][READ_PIPE_IDX];
	}
	else
	{
		if(ms->fd.infile == STDIN_FILENO)
		{
			ms->exe.infd = ms->fd.pipe[cmd->id - 2][READ_PIPE_IDX];
			ms->data.pipe_use = false;
		}
		else if(ms->fd.outfile == STDOUT_FILENO)
		{
			ms->exe.outfd = ms->fd.pipe[cmd->id - 1][WRITE_PIPE_IDX];
			ms->data.pipe_use = true;
		}
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
	ms->fd.infile = STDIN_FILENO;
	ms->fd.outfile = STDOUT_FILENO;
	
}

void	reset_t_var(t_minishell *ms)
{
	ms->oldpwd_var.name = NULL;
	ms->oldpwd_var.operator = NULL;
	if(ms->oldpwd_var.value)
		free (ms->oldpwd_var.value);
	ms->oldpwd_var.value = NULL;
	
	ms->pwd_var.name = NULL;
	ms->pwd_var.operator = NULL;
	if(ms->pwd_var.value)
		free(ms->pwd_var.value);
	ms->pwd_var.value = NULL;
}
