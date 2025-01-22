
#ifndef EXEC_H
# define EXEC_H

# include "tokenizing.h"

typedef struct s_exe
{
	int		infd;
	int		outfd;
	char	*name;	
	char	*path;
	char	**argv;
	char	**envp;	
}	t_exe;

/* ******************************   EXEC   ******************************** */
// exex.c
bool	exec(t_minishell	*ms);

#endif //EXEC_H