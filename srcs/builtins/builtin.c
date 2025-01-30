/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:04:56 by fwu               #+#    #+#             */
/*   Updated: 2025/01/30 14:55:35 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strtolower(char *str)
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

bool is_builtin(t_minishell *ms)
{
	char *str;

	str = ft_strtolower(ms->exe.name);
	if (ft_strcmp(str, ENV) == 0 || ft_strcmp(str, PWD) == 0 
		|| ft_strcmp(str, EXIT) == 0 || ft_strcmp(str, ECHO) == 0
		|| ft_strcmp(str, EXPORT) == 0 || ft_strcmp(str, CD) == 0)
	{
		free(ms->exe.name);
		ms->exe.name = ft_strdup(str);
		free(str);
		str = NULL;
		return(true);
	}
	
	free(str);
	str = NULL;
	return(false);
}

bool	builtin(t_minishell *ms)
{
	if (ft_strncmp(ms->exe.name, ENV, 3) == 0)
		ft_env(ms->exe.argv, *(ms->exe.envp));
	else if (ft_strncmp(ms->exe.name, PWD, 3) == 0)
		ft_pwd(ms->exe.argv, *(ms->exe.envp));
	else if (ft_strncmp(ms->exe.name, EXIT, 4) == 0)
		ft_exit(ms);
	else if (ft_strncmp(ms->exe.name, ECHO, 4) == 0)
		ft_echo(ms);
	else if (ft_strncmp(ms->exe.name, EXPORT, 6) == 0)
		ft_export(ms->exe.argv, ms->exe.envp);
	else if (ft_strncmp(ms->exe.name, CD, 2) == 0)
		ft_cd(ms->exe.argv, ms->exe.envp);
	// free(ms->exe.name);
	// ms->exe.name = NULL;
	return (true);
}
