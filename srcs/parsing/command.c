/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:06:02 by mabril            #+#    #+#             */
/*   Updated: 2025/03/24 10:40:36 by mike             ###   ########.fr       */
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

bool	cmd_if_not_exits_cur_cmd(t_minishell *ms)
{
	t_data	*d;
	
	d = &ms->data;
	d->cur_cmd = creat_nod(ms);
	d->count_cmd += 1;
	d->arg_c = 0;
	d->i = 0;
	d->cur_cmd->id = d->count_cmd;
	d->token_tem = d->token_cur;
	if(!d->token_tem)
		return(true);		
	while (d->token_tem && d->token_tem->type != PIPE)
	{
		if(d->token_tem->type == CMD && (!d->token_last || d->token_last->type != REDIR ))
		d->arg_c++;
		d->token_last = d->token_tem;
		d->token_tem = d->token_tem->next;
	}
	return(false);
}

void	create_cmd(t_minishell *ms)
{
	t_data	*d;
	
	d = &ms->data;
	if(!d->cur_cmd)
	{
		if(cmd_if_not_exits_cur_cmd(ms))
			return;
	}
	if (!d->cur_cmd->argv && d->arg_c != 0 && d->token_cur->type != REDIR )
	{
		d->cur_cmd->argv = (char **)calloc(sizeof(char *) , (d ->arg_c + 1));
		d->cur_cmd->argv[d->arg_c] = NULL;
		d->cur_cmd->argv[d->i++] = ft_strdup(d->token_cur->value);
	}
}

void	buil_cmd_list(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	d->token_cur = d->token_list;
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
