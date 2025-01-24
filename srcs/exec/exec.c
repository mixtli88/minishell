/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:14:36 by fwu               #+#    #+#             */
/*   Updated: 2025/01/23 16:39:22 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


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