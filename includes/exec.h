
#ifndef EXEC_H
# define EXEC_H

# include "tokenizing.h"


/* ******************************   EXEC   ******************************** */
// exex.c
bool	exec(t_minishell	*ms);


void 	ini_exe(t_minishell *ms);
int 	do_execve(t_minishell *ms, t_cmd *cmd);
void 	free_exe(t_minishell *ms);
int	find_path_exe(t_minishell *ms);
void fork_execve(t_minishell *ms, t_cmd *cmd);
// void fork_execve(t_minishell *ms, t_cmd *cmd, int pipesfd);


#endif //EXEC_H