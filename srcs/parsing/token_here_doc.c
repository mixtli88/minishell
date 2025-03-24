#include "../../includes/minishell.h"

bool its_heredoc(t_minishell *ms)
{
	t_data	*d;
	
	d = &ms->data;
	if (ft_strcmp(d->token_cur->value, "<<") == 0)
	{
		if(d->new_readline)
		{
			free(d->new_readline);
			d->new_readline = NULL;			
		}
		return (true);
	}
	return (false);
}

void ft_heredoc(t_minishell *ms, t_rdir *new)
{
	t_data *d;
	char *n_l;

	d = &ms->data;
	new->fd_rdir = NULL;
	while(1)
	{
		n_l = ft_strdup("\n");
		d->new_readline = readline(BLUE"> "RESET);
		if (g_signal_status == 2 || !d->new_readline)
		{
			if (!d->new_readline)
				error_quote();
			d->flag = -1;
			free(n_l);
			return ;
		}
		if(ft_strcmp(d->new_readline, d->token_cur->next->value) == 0)
		{
			free(n_l);
			break;
		}
		d->new_readline = ft_strcat(&d->new_readline, &n_l);
		new->fd_rdir = ft_strcat(&new->fd_rdir, &d->new_readline);
	}	
}
