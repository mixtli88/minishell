/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:04:56 by fwu               #+#    #+#             */
/*   Updated: 2025/01/21 17:11:17 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	builtin(t_minishell *ms)
{
	char	*cmd;
	char	**argv;
	char	**envp;

	cmd = ms->data.cmd_list->argv[0];
	argv = ms->data.cmd_list->argv;
	envp = ms->envp;
	if (ft_strncmp(cmd, "env", 3) == 0)
		ft_env(argv, envp);
	else if (ft_strncmp(cmd, "pwd", 3) == 0)
		ft_pwd(argv, envp);
	else if (ft_strncmp(cmd, "exit", 4) == 0)
		ft_exit(argv);
	else if (ft_strncmp(cmd, "echo", 4) == 0)
		ft_echo(argv);
	else if (ft_strncmp(cmd, "export", 6) == 0)
		ft_export(argv, &envp);
	else if (ft_strncmp(cmd, "cd", 2) == 0)
		ft_cd(argv, &envp);
	
	// char *argv[] = {"c=", "ss1=2", NULL};
	// ft_export(argv, &(ms->envp));
	// char *argv2[] = {"s=5", NULL};
	// ft_export(argv2, &(ms->envp));
	// ft_env(ms->envp);

	// ft_echo(argv);
	// ft_cd(argv, ms->envp);

	// char *argv2[] = {"ls", "-l", NULL};
	// char *path = "/bin/ls";
	// execve(path, argv2, ms->envp);
	return (true);
}
