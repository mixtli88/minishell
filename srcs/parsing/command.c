/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:06:02 by mabril            #+#    #+#             */
/*   Updated: 2025/02/26 09:37:08 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*creat_nod(t_minishell *ms)
{
	t_cmd	*new;
	t_cmd	*last;
	t_data	*d;

	d = &ms->data;
	new = malloc(sizeof(t_cmd));
	last = NULL;
	init_new_cmd(&new);
	new->next = NULL;
	if ((d)->cmd_list == NULL)
		(d)->cmd_list = new;
	else
	{
		last = (d)->cmd_list;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return (new);
}

void	buil_cmd_list(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	d->token_cur = d->tok_list;
	while (d->token_cur)
	{
		if (d->token_cur && d->token_cur->type == CMD)
			tok_is_cmd(ms);
		else if (d->token_cur->type == PIPE)
			tok_is_pipe(ms);
		else if (d->token_cur->type == REDIR)
			tok_is_redi(ms);
		if (d->flag == -1)
			break;
	}
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
		g_signal_status = 1;
		d->new_readline = readline(">");
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
