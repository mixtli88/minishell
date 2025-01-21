/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:06:02 by mabril            #+#    #+#             */
/*   Updated: 2025/01/20 20:50:31 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*creat_cmd(t_minishell *ms)
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
		else if (d->token_cur->type == LOGIC)
			tok_is_pipe(ms);
		else if (d->token_cur->type == PIPE)
			tok_is_pipe(ms);
		else if (d->token_cur->type == REDIR)
			tok_is_redi(ms);
		d->token_cur = d->token_cur->next;
	}
}
