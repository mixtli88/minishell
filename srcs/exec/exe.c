/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:06:19 by fwu               #+#    #+#             */
/*   Updated: 2025/01/23 00:48:43 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static bool	create_t_exe(t_exe **exe)
{
	*exe = (t_exe *)ft_calloc(1, sizeof(t_exe));
	if (!*exe)
		return (false);
	return (true);
}

static char *find_path_exe(char *name, char ***envp)
{
	int		i;
	char	**paths;
	char	*full_path;

	i = -1;
	paths = ft_split(ft_getenv("PATH", *envp), ':');
	while (paths[++i])
	{
		full_path = ft_strjoin(ft_strjoin(paths[i], "/"), name);
		if (access(full_path, X_OK) == 0)
		{
			free_table(paths);
			return (full_path);
		}
	}
	free_table(paths);
	return (NULL);
}

bool	prepare_t_exe(t_fd *fd, t_cmd	*cmd,  char ***envp, t_exe **exe)
{
	(void) fd;
	if (!create_t_exe(exe))
		return (false);
	(*exe)->name = cmd->argv[0];
	(*exe)->path = find_path_exe((*exe)->name, envp);
	(*exe)->argv = cmd->argv;
	(*exe)->envp = envp;
	return (true);
}

void	free_t_exe(t_exe **exe)
{
	if (!*exe)
		return ;
	// free_exe_argv(*exe);
	free (*exe);
	*exe = NULL;
}

// execute first cmd
// execute last cmd
// execute mid cmd
// static void	get_exe_fd(int cur_cmd_idx, t_exe *exe, t_fd *fd, t_arg *arg)
// {
// 	if (cur_cmd_idx == 0)
// 	{
// 		exe->infd = fd->infile;
// 		exe->outfd = fd->pipe[INI_PIPE_IDX + arg->here_doc][WRITE_PIPE_IDX];
// 	}
// 	else if (cur_cmd_idx == arg->cmd_num - 1)
// 	{
// 		exe->infd = fd->pipe[cur_cmd_idx + arg->here_doc - 1][READ_PIPE_IDX];
// 		exe->outfd = fd->outfile;
// 	}
// 	else
// 	{
// 		exe->infd = fd->pipe[cur_cmd_idx + arg->here_doc - 1][READ_PIPE_IDX];
// 		exe->outfd = fd->pipe[cur_cmd_idx + arg->here_doc][WRITE_PIPE_IDX];
// 	}
// }

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

