
#include "../../includes/minishell.h"

void error_execve(t_minishell *ms)
{
    ft_putstr_fd("mini: ", STDERR_FILENO);
    ft_putstr_fd(ms->exe.argv[0], STDERR_FILENO);
	if (errno == EACCES || errno == EISDIR)
    {
		if(errno == EISDIR)
			 ft_putendl_fd(": Is a directory", STDERR_FILENO);
        else
			 ft_putendl_fd(": Permission denied", STDERR_FILENO);
        exit(126);  
    }
    else if (errno == ENOENT)
    {
        ft_putendl_fd(": command not found", STDERR_FILENO);
        exit(127);  // Código de salida 127 para "command not found"
    }
    else if (errno == ENOENT)
    {
        ft_putendl_fd(": command not found", STDERR_FILENO);
        exit(127);  // Código de salida 127 para "command not found"
    }
    else
    {
        ft_putendl_fd(": unknown error", STDERR_FILENO);
        exit(1);  // Código de salida 1 para otros errores
    }
}

void error_open_file(t_minishell *ms,   char *file)
{
    int err;

	if (access(file, F_OK) == -1)
        error_msg(ms, file, ENOENT, ERROR_REDIRECT);
    else if (is_directory(file, &err))
        error_msg(ms, file, EISDIR, ERROR_REDIRECT);
    else if(access(file, X_OK) == -1)
        error_msg(ms, file, EACCES, ERROR_REDIRECT);
	
    ms->status = 1;
	ms->data.flag = -1;
}

void error_msg(t_minishell *ms, char *str, int err, int context)
{
    ft_putstr_fd("mini: ", STDERR_FILENO);
    ft_putstr_fd(str, STDERR_FILENO);
    if (err == ENOENT)
        ft_putendl_fd(": No such file or directory", STDERR_FILENO);
    else if (err == EISDIR)
        ft_putendl_fd(": Is a directory", STDERR_FILENO);
    else if (err == EACCES)
        ft_putendl_fd(": Permission denied", STDERR_FILENO);
    else if (err == EISCMD)
        ft_putendl_fd(": command not found", STDERR_FILENO);
    if (context == ERROR_REDIRECT)
        ms->status = 1;
    else if (context == ERROR_EXEC)
    {
        if (err == EACCES || err == EISDIR)
            ms->status = 126;
        else if (err == ENOENT || err == EISCMD)
            ms->status = 127;
        else
            ms->status = 1;
    }
    else
        ms->status = 1;
}
