/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:45:51 by fwu               #+#    #+#             */
/*   Updated: 2025/01/30 16:15:51 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	execute_cmd(t_minishell	*ms, t_cmd *cmd)
{
	int	status;	
	int	id = 0;
	
	if (is_builtin(ms))
		builtin(ms);
	else
	{
		id = fork();
		if (id == -1)
			return (false);
		if (id == 0)
		{
			 printf("ms->exe.infd: %d\n", ms->exe.infd);
			 printf("ms->exe.outfd: %d\n", ms->exe.outfd);
			if (dup2(ms->exe.infd, STDIN_FILENO) == -1)
				return (false);
			if (dup2(ms->exe.outfd, STDOUT_FILENO) == -1)
				return (false);
			close_fd(ms, cmd);
			if (execve(ms->exe.path, ms->exe.argv, *(ms->exe.envp)) == -1)
			{
				ft_putstr_fd("minishell: ", STDERR_FILENO);
				ft_putstr_fd(ms->exe.argv[0], STDERR_FILENO);
				ft_putendl_fd(": command not found", STDERR_FILENO); 
				exit(127);
			}
		}
		else
			waitpid(id, &status, 0); // Esperar al hijo
	}	
	if (ms->exe.outfd != STDOUT_FILENO)
				close(ms->exe.outfd); // Cerrar la escritura del pipe actual en el padre
			if (ms->exe.infd != STDIN_FILENO)
				close(ms->exe.infd); //
	return (true);
}
	// if (ft_strncmp(str, "", 1) == 0)
	// 	error_path_cmd(cmd);
	// if (ft_strncmp(str, "/", 1) == 0)
	// 	error_directory(ms);
	// if (ft_strncmp(str, "!", 1) == 0)
	// 	error_syntax(ms);
	// if (ft_strncmp(str, ":", 1) == 0)
	// 	ft_minishell_loop(ms);	



bool	fork_and_execute(t_minishell	*ms, t_cmd *cmd)
{	
	while (cmd)
	{ 
		prepare_t_exe(ms, cmd);
		execute_cmd(ms, cmd);
		reset_t_exe(ms);
		// free(ms->exe.path);
		// ms->exe.path = NULL;
		cmd = cmd->next;
	}
	
	return (true);
}
