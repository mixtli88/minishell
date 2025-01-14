/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:06:02 by mabril            #+#    #+#             */
/*   Updated: 2025/01/14 13:33:16 by mabril           ###   ########.fr       */
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
	t_token *tok_curr;
	
	(*data)->token_curr = (*data)->tok_list;
	tok_curr = (*data)->token_curr;
	while(tok_curr)
	{
		if(tok_curr && tok_curr->type == CMD)
		{
			tok_is_cmd(data);
		}
		else if( tok_curr->type == PIPE )
		{
			if(!(*data)->curr_cmd)
				error_free(data);
			else
				(*data)->curr_cmd = NULL;
		}		
		else if (tok_curr->type ==  REDIR)
		{
			tok_is_redi(data);
			tok_curr = tok_curr->next;	
		}
		(*data)->i++;
		tok_curr = tok_curr->next;	
	}
}
