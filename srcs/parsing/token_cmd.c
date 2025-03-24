#include "../../includes/minishell.h"

void	tok_is_cmd(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	d->token_tem = d->token_cur;
	if (!d->cur_cmd || !d->cur_cmd->argv)
		create_cmd(ms);
	else
		d->cur_cmd->argv[d->i++] = ft_strdup(d->token_cur->value);
	d->token_cur = d->token_cur->next;
}


