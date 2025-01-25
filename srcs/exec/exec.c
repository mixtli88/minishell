/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:14:36 by fwu               #+#    #+#             */
/*   Updated: 2025/01/25 09:51:56 by mike             ###   ########.fr       */
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
	t_exe	*exe;
	t_cmd	*cmd;

	exe = &ms->exe;
	cmd = ms->data.cmd_list;
	while (cmd && cmd->argv[0])
	{
		exe->name = cmd->argv[0];
		exe->argv = cmd->argv;
		exe->envp = ms->envp;
		if (do_execve(ms, cmd))
		{
			builtin(ms);
			if (exe->name)
				free(exe->name);
		}
		else
		{
			fork_execve(ms, cmd);
		}
		cmd = cmd->next;
	}
	return (true);
}

// bool	exec(t_minishell	*ms)
// {
// 	t_exe	*exe;
// 	t_cmd	*cmd;
// 	int i;

// 	exe = &ms->exe;
// 	cmd = ms->data.cmd_list;
// 	while (cmd && cmd->argv[0])
// 	{
// 		exe->name = cmd->argv[0];
// 		exe->argv = cmd->argv;
// 		exe->envp = ms->envp;
// 		fork_execve(ms, cmd);
// 		cmd = cmd->next;
// 	}
	
// 	return (true);
// }

// ************** GESTIION PIPE ********************

// bool    exec(t_minishell    *ms)
// {   
//     t_cmd   *cmd;
//     int pipesfd[2];
//      t_exe   *exe;
	 
//     cmd = ms->data.cmd_list;
// 	exe = &ms->exe;
//     while (cmd && cmd->argv[0])
//     {
//         if(cmd->next && pipe(pipesfd) == -1)
//         {
//             perror("pipe");
//             return(false);
//     	}
// 		exe->name = cmd->argv[0];
//         exe->argv = cmd->argv;
//         exe->envp = ms->envp;
		
//         fork_execve(ms, cmd, pipesfd);
//         cmd = cmd->next;
//     }
//     return (true);
// }



	// char *argv[] = {"c=", "ss1=2", NULL};
	// ft_export(argv, &(ms->envp));
	// char *argv2[] = {"s=5", NULL};
	// ft_export(argv2, &(ms->envp));
	// ft_env(ms->envp);

	// ft_echo(argv);
	// ft_cd(argv, ms->envp);

	// char *argv2[] = {"ls", "-l", NULL};
	// char *path = "/bin/ls";
	// execve(path, argv2, ms->envp);	DONE