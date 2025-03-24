#include "../../includes/minishell.h"

void	close_fd(t_minishell	*ms)
{
	int i;
	i = 0;
	while(i < ms->fd.pipe_num)
	{
		if (ms->fd.pipe[i][READ_PIPE_IDX] != STDIN_FILENO) 
            close(ms->fd.pipe[i][READ_PIPE_IDX]);
		if (ms->fd.pipe[i][WRITE_PIPE_IDX] != STDOUT_FILENO)
			close(ms->fd.pipe[i][WRITE_PIPE_IDX]);
		i++;	
	}
}

void	close_fd_exe(t_minishell	*ms)
{
	if (ms->exe.outfd != STDOUT_FILENO)
		close(ms->exe.outfd);
	if (ms->exe.infd != STDIN_FILENO)
		close(ms->exe.infd);
}

void	free_t_fd(t_minishell	*ms)
{
	int	i;
	
	i = 0;
	if (ms->fd.pipe)
	{
		while (i < ms->fd.pipe_num)
		{
			free(ms->fd.pipe[i]);
			i++;
		}
		free(ms->fd.pipe);
		ms->fd.pipe = NULL;
	}
	ms->fd.infile = 0;
	ms->fd.outfile = 0;
	ms->fd.pipe_num = 0;
	ms->fd.cmd_num = 0; 
}

void	reset_t_exe(t_minishell *ms)
{
	if (ms->exe.infd != STDIN_FILENO)
		close(ms->exe.infd);
	if (ms->exe.outfd != STDOUT_FILENO)
		close(ms->exe.outfd);
	ms->exe.infd = 0;
	ms->exe.outfd = 0;
	if (ms->exe.name)
		free(ms->exe.name);
	ms->exe.name = NULL;
	if (ms->exe.path)
		free(ms->exe.path);
	ms->exe.path = NULL;
	ms->exe.argv = NULL;
	ms->exe.envp = NULL;
	ms->fd.infile = STDIN_FILENO;
	ms->fd.outfile = STDOUT_FILENO;	
}
