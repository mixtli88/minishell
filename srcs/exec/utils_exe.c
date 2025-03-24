/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:06:19 by fwu               #+#    #+#             */
/*   Updated: 2025/03/24 12:56:18 by mike             ###   ########.fr       */
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

bool	access_doc(t_minishell *ms)
{
	ms->exe.arcg = 0;
	if (access(ms->exe.name, F_OK) == -1)
		return error_msg(ms, ms->exe.name, ENOENT, ERROR_EXEC), true;
	if (is_directory(ms->exe.name, &ms->err))
		return error_msg(ms, ms->exe.name, EISDIR, ERROR_EXEC), true;
	if (access(ms->exe.name, X_OK) == -1)
		return error_msg(ms, ms->exe.name, EACCES, ERROR_EXEC), true;
	ms->exe.path = ft_strdup(ms->exe.name);
	return(false);
}

void	prepare_t_exe(t_minishell *ms, t_cmd *cmd)
{
	int i;
	
	i = -1;
	ms->exe.arcg = 0;
	get_fd_exe(ms, cmd);
	if(cmd->argv && cmd->argv[0])
	{
		while(cmd->argv[++i])
			ms->exe.arcg++;
		ms->exe.name = ft_strdup(cmd->argv[0]);
		if (ms->exe.name[0] == '/' || (ms->exe.name[0] == '.' && ms->exe.name[1] == '/'))
		{
			if(access_doc(ms))
				ms->data.flag = -1;	
		}	
		else if(!is_builtin(ms))
		{
			ms->exe.path = find_path_exe(ms);
			if (!ms->exe.path)
				return error_msg(ms, ms->exe.name, EISCMD, ERROR_EXEC);
		}
	}
	ms->exe.argv = cmd->argv;
	ms->exe.envp = ms->envp;
}

int creat_tem_heredoc(char *heredoc)
{
	int fd;
	char *heredoc_file;

	heredoc_file = "/tmp/heredoc";
	fd = open(heredoc_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(fd == -1)
		return (-1);
	if(heredoc)
		write(fd, heredoc, ft_strlen(heredoc));
	close(fd);
	return (open(heredoc_file, O_RDONLY));
}

void proces_execve(t_minishell *ms)
{
	if (dup2(ms->exe.infd, STDIN_FILENO) == -1)
	{
		perror_cmd("dup2 (infd)");
		exit(1);
	}
	if (dup2(ms->exe.outfd, STDOUT_FILENO) == -1)
	{
		perror_cmd("dup2 (outfd)");
		exit(1);
	}
	if (ms->exe.infd != STDIN_FILENO)
		close(ms->exe.infd);
	if (ms->exe.outfd != STDOUT_FILENO)
		close(ms->exe.outfd);
	close_fd(ms);
	if (execve(ms->exe.path, ms->exe.argv, *(ms->exe.envp)) == -1)
		error_execve(ms);
}
