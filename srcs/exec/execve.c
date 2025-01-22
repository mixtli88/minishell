/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:32:25 by mabril            #+#    #+#             */
/*   Updated: 2025/01/22 12:48:25 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int do_execve(t_minishell *ms, t_cmd *cmd)
{
	char *str;
	int phind;

	phind = 0;
	str = ft_strtolower(ms->exe.name);
	if (ft_strcmp(str, "cd") == 0 || ft_strcmp(str, "echo") == 0
		|| ft_strcmp(str, "env") == 0 || ft_strcmp(str, "envp") == 0
		|| ft_strcmp(str, "error") == 0 || ft_strcmp(str, "exit") == 0
		|| ft_strcmp(str, "export") == 0 || ft_strcmp(str, "pwd") == 0)
	{
		ms->exe.name = ft_strdup(str);
		free(str);
		phind = 1;
	}
	if (ft_strncmp(str, "", 1) == 0)
		error_path_cmd(cmd);
	if (ft_strncmp(str, "/", 1) == 0)
		error_directory(ms);
	if (ft_strncmp(str, "!", 1) == 0)
		error_syntax(ms);
	if (ft_strncmp(str, ":", 1) == 0)
		ft_minishell_loop(ms);
	// if (ft_strncmp(ms->data.token_cur->value, "|", 1) == 0)
	// 	ft_minishell_loop(ms);
	return(phind);
}

int	find_path_exe(t_minishell *ms)
{
	char	**paths;
	int		i;
	t_data	*d;

	d = &ms->data;
	i = -1;
	paths = ft_split(getenv("PATH"), ':');
	while (paths[++i])
	{
		free(d->full_path);
		d->full_path = ft_strjoin(ft_strjoin(paths[i], "/"), ms->exe.name);
		if (access(d->full_path, X_OK) == 0)
		{
			ms->exe.path = ft_strdup(d->full_path);
			free_table(paths);
			return(1) ;
		}
	}
	free_table(paths);
	return(0);
}


void ini_exe(t_minishell *ms)
{

	t_exe	*exe;

	exe = &ms->exe;
	if (exe)
	{
		exe->argv = NULL;
		exe->argv = NULL;
		exe->envp = NULL;
		exe->name = NULL;
		exe->path = NULL;
		exe->infd = 0;			//check this
		exe->outfd = 0;			//check this
		exe = NULL;
	}		
}

void free_exe(t_minishell *ms)
{
	t_exe	*exe;

	exe = &ms->exe;
	if (exe)
	{
		if (exe->argv)
			free(exe->argv);
		if (exe->envp)
			free(exe->envp);
		if (exe->name)
			free(exe->name);
		if (exe->path)
			free(&exe->path);
		ini_exe(ms);
		exe = NULL;
	}	
}

