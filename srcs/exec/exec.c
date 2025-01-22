/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:14:36 by fwu               #+#    #+#             */
/*   Updated: 2025/01/21 19:52:11 by fwu              ###   ########.fr       */
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

bool	exec(t_minishell	*ms)
{
	t_exe	exe;
	t_cmd	*cmd;

	cmd = ms->data.cmd_list;
	while (cmd && cmd->argv[0])
	{
		exe.name = ft_strtolower(cmd->argv[0]);
		exe.argv = cmd->argv;
		exe.envp = ms->envp;
		builtin(&exe);
		if (exe.name)
			free(exe.name);
		cmd = cmd->next;
	}

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
