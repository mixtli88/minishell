
#include "../../includes/minishell.h"

void error_execve(t_minishell *ms)
{
    ft_putstr_fd("mini: ", STDERR_FILENO);
    ft_putstr_fd(ms->exe.argv[0], STDERR_FILENO);
    ft_putendl_fd(": command not found", STDERR_FILENO); 
    exit(127);

}

void error_open_file(t_minishell *ms,   char *file)
{
	ft_putstr_fd("mini: ", STDERR_FILENO);
	ft_putstr_fd(file, STDERR_FILENO);
	ft_putendl_fd(": No such file or directory", STDERR_FILENO);
	ms->status = 1;
	ms->data.flag = -1;
}