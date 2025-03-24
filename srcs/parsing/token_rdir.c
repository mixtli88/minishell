#include "../../includes/minishell.h"

void	type_rdir(t_minishell *ms, t_rdir **new)
{
	t_data	*d;
	
	d = &ms->data;
	if (ft_strcmp(d->token_cur->value, "<") == 0)
	(*new)->type = SINGLE_IN;
	else if (ft_strcmp(d->token_cur->value, ">") == 0)
	(*new)->type = SINGLE_OUT;
	else if (ft_strcmp(d->token_cur->value, "<<") == 0)
	(*new)->type = DOUBLE_IN;
	else if (ft_strcmp(d->token_cur->value, ">>") == 0)
	(*new)->type = DOUBLE_OUT;
	
}

void creat_nod_rdir(t_minishell *ms)
{
	t_data	*d;
	t_rdir	*new = NULL;
	t_rdir	*last = NULL;
	
	d = &ms->data;
	last = NULL;
	new = malloc(sizeof(t_rdir));
	type_rdir(ms, &new);
	new->next = NULL;
	if(its_heredoc(ms))
		ft_heredoc(ms, new);
	else
		new->fd_rdir = ft_strdup(d->token_cur->next->value);
	if (d->cur_cmd->rdir == NULL)
		d->cur_cmd->rdir = new;
	else
	{
		last = d->cur_cmd->rdir;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

void	tok_is_redi(t_minishell *ms)
{
	t_data	*d;
	
	d = &ms->data;
	if (!d->token_cur->next || d->token_cur->next->type != CMD)
	error_syntax(ms);
	else 
	{
		if (!d->cur_cmd)
		create_cmd(ms);
		creat_nod_rdir(ms);
		d->token_cur = d->token_cur->next;
		d->token_cur = d->token_cur->next;
	}
}