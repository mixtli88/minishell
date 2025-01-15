/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:06:02 by mabril            #+#    #+#             */
/*   Updated: 2025/01/14 19:15:49 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


t_cmd *creat_cmd(t_data **data)
{
	t_cmd *new;
	t_cmd *last;
	
	new = malloc(sizeof (t_cmd));
	last = NULL;
	init_new_cmd(&new);
	new->next = NULL;
	if((*data)->cmd_list == NULL)
		(*data)->cmd_list = new;
	else
	{
		last = (*data)->cmd_list;
		while(last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return(new);
}

void buil_cmd_list(t_data **data)
{
	t_data *d;
	
	d = *data;
	d->token_cur = d->tok_list;
	while(d->token_cur)
	{
		if(d->token_cur && d->token_cur->type == CMD)
			tok_is_cmd(data);
		else if( d->token_cur->type == PIPE )
			tok_is_pipe(data);
		else if (d->token_cur->type ==  REDIR)
			tok_is_redi(data);	
		(*data)->i++;
		d->token_cur = d->token_cur->next;	
	}
}
