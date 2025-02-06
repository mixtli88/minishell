#include "../../includes/minishell.h"

void     get_cd_path(t_minishell *ms, t_cmd *cmd)
{
    t_data	*d;

	d = &ms->data;
    if (!cmd->argv[1])
            d->path = ft_getenv("HOME", *ms->envp);
        else if (ft_strcmp(cmd->argv[1], ".") == 0)
           d->path = ft_strdup(ms->oldpwd_var.value);
        else if (ft_strcmp(cmd->argv[1], "..") == 0)
        {
            d->last_slash = ft_strrchr(ms->oldpwd_var.value, '/');
            if (d->last_slash && d->last_slash != ms->oldpwd_var.value)
                *d->last_slash = '\0';
            d->path = ft_strdup(ms->oldpwd_var.value);
        }
        else if (cmd->argv[1][0] == '/')
            d->path = ft_strdup(cmd->argv[1]);
        else
            d->path = ft_strcat(&(char *){ft_strjoin(ms->oldpwd_var.value, "/")},
                &(char *){ft_strdup(cmd->argv[1])}); 
}
