/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:41:01 by mabril            #+#    #+#             */
/*   Updated: 2025/01/23 16:19:14 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


// void fork_execve(t_minishell *ms, t_cmd *cmd)
// {
// // 	pid_t	pid;
// 	// int		status;
// 	t_exe	*exe;

// 	exe = &ms->exe;
// 	pid = fork();
// 	if(pid == 0)
// 	{
		// if(do_execve(ms, cmd))
// 		{
// 			builtin(ms);
// 			if (exe->name)
// 				free(exe->name);
// 		}
// 		else if( find_path_exe(ms))
// 			execve(exe->path, exe->argv, *(exe->envp));
// 		else	
// 			error_path_cmd(cmd);
		// exit(EXIT_SUCCESS);
	// }
	// else if(pid > 0)
	// {
	// 	waitpid(pid, &status, 0);
	// }
	// else
	// 	perror("fork");
	
	// if (ft_strcmp(exe->name, "exit") == 0|| ft_strcmp(exe->name, "EXIT") == 0)
	// 	exit(EXIT_SUCCESS);
// }

// ************** GESTIION PIPE ********************


// void fork_execve(t_minishell *ms, t_cmd *cmd, int pipesfd[2])
// {
//     pid_t   pid;
//     int     status;
//     t_exe   *exe;
// 	int 	prev_pipe;
	
// 	prev_pipe = -1;
//     exe = &ms->exe;
//     pid = fork();
// 	if(pid = -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
//     if(pid == 0)
//     {
// 		if(prev_pipe != -1)
// 		{
// 			dup2(prev_pipe, STDERR_FILENO);
// 			close(prev_pipe);
// 		}
// 		if(cmd->next)
// 		{
// 			close(pipesfd[0]);
// 			dup2(pipesfd[1], STDERR_FILENO);
// 			close(pipesfd[1]);
// 		}
        
//         if(do_execve(ms, cmd))
//             builtin(ms);
//         else if( find_path_exe(ms))
//             execve(exe->path, exe->argv, exe->envp);
//         else    
//             error_path_cmd(cmd);
//         exit(EXIT_FAILURE);
//     }
// 	if(prev_pipe != -1)
// 		close(prev_pipe);
//     else if(pid > 0)
//     {
//         waitpid(pid, &status, 0);
               
//     }
//     else
//         perror("fork");
// }








