#include "../../includes/minishell.h"

void	ft_unset(t_minishell *ms, char *var)
{	
	int	i;
    int len;
	char **envp;
	
	i = 0;
	envp = *(ms->envp);
    len = ft_strlen(var);
    if (!var || !envp || !envp[i] )
		return;
	while (envp[i])
	{
		if(ft_strncmp(envp[i], var, len) == 0 && envp[i][len] == '=')
		{
			free(envp[i]);
			while(envp[i])
			{
				envp[i] = envp[i + 1];
				i++;
			}
			envp[i] = NULL;
			return;
		}
		i++;
	}
}
