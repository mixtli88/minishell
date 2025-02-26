/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:06:19 by fwu               #+#    #+#             */
/*   Updated: 2025/02/25 19:25:54 by mike             ###   ########.fr       */
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
