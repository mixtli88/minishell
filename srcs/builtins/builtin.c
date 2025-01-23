/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:04:56 by fwu               #+#    #+#             */
/*   Updated: 2025/01/23 16:18:23 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


bool	builtin(t_exe	*exe)
{
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
	// else if (ft_strncmp(exe->name, CD, 2) == 0)
	// 	ft_cd(exe->argv, exe->envp);
	return (true);
}

	// if (exe->name)
    // 	free(exe->name);