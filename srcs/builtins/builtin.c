/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:04:56 by fwu               #+#    #+#             */
/*   Updated: 2025/01/25 09:50:12 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_strtolower(char *str)
{
	char	*tmp_str;
	int		i;

	tmp_str = ft_strdup(str);
	i = 0;
	while (tmp_str && tmp_str[i])
	{
		tmp_str[i] = ft_tolower(tmp_str[i]);
		i++;
	}
	return (tmp_str);
}

bool is_builtin(t_exe *exe)
{
	char *str;

	str = ft_strtolower(exe->name);
	if (ft_strcmp(str, ENV) == 0 || ft_strcmp(str, PWD) == 0 
		|| ft_strcmp(str, EXIT) == 0 || ft_strcmp(str, ECHO) == 0
		|| ft_strcmp(str, EXPORT) == 0 || ft_strcmp(str, CD) == 0)
	{
		free(str);
		return(true);
	}
	if (str)
		free(str);
	return(false);
}

bool	builtin(t_exe	*exe)
{
	// ft_putendl_fd("builtin", STDOUT_FILENO);
	// t_exe	*exe;
	
	// exe = &ms->exe;
	if (ft_strncmp(exe->name, ENV, 3) == 0)
		ft_env(exe->argv, *(exe->envp));
	else if (ft_strncmp(exe->name, PWD, 3) == 0)
		ft_pwd(exe->argv, *(exe->envp));
	else if (ft_strncmp(exe->name, EXIT, 4) == 0)
		ft_exit(exe->argv);
	else if (ft_strncmp(exe->name, ECHO, 4) == 0)
		ft_echo(exe->argv);
	else if (ft_strncmp(exe->name, EXPORT, 6) == 0)
		ft_export(exe->argv, exe->envp);
	else if (ft_strncmp(exe->name, CD, 2) == 0)
		ft_cd(exe->argv, exe->envp);
	return (true);
}
