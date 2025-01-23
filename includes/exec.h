
#ifndef EXEC_H
# define EXEC_H

# include "tokenizing.h"

# define WRITE_PIPE_IDX 1
# define READ_PIPE_IDX 0

typedef struct s_fd
{
	int	infile;
	int	outfile;
	// int	infile_status;
	// int	outfile_status;
	int	pipe_num;
	int	(*pipe)[2];
}	t_fd;

/* ******************************   EXEC   ******************************** */
// fd.c
bool	prepare_t_fd(t_fd **fd, t_minishell	ms);
void	close_fd(t_fd *fd);
void	free_t_fd(t_fd	**fd);
// exe.c
void	free_t_exe(t_exe **exe);
bool	prepare_t_exe(t_fd *fd, t_cmd	*cmd,  char ***envp, t_exe **exe);
// execute.c
bool	fork_and_execute(t_fd *fd, t_minishell	*ms);
// pipex.c
bool	pipex(t_minishell	*ms);


// exex.c
// bool	exec(t_minishell	*ms);

// void 	ini_exe(t_minishell *ms);
// int 	do_execve(t_minishell *ms, t_cmd *cmd);
// void 	free_exe(t_minishell *ms);
// int	find_path_exe(t_minishell *ms);
// void fork_execve(t_minishell *ms, t_cmd *cmd);
// void fork_execve(t_minishell *ms, t_cmd *cmd, int pipesfd);


#endif //EXEC_H