/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:15:33 by mabril            #+#    #+#             */
/*   Updated: 2025/02/15 23:26:49 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_data(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	d->input = NULL;
	d->buf_idx = 0;
	d->i = 0;
	d->count_cmd = 0;
	d->quote = 0;
	d->count_quote = 0;
	d->new_readline = NULL;
	d->new_inp = NULL;
	d->full_path = NULL;
	d->var = NULL;
	d->envp = NULL;
	d->buff[0] = '\0';
	d->var_buf[0] = '\0';
	d->tok_list = NULL;
	d->token_cur = NULL;
	d->tok_tem = NULL;
	d->cmd_list = NULL;
	d->cur_cmd = NULL;
	d->path = NULL;
	d->last_slash = NULL;
	d->flag = 0;
	d->pipe_use= false;
	g_signal_status = 0;
}

void	init_new_token(t_token **new)
{
	t_token	*n;

	n = *new;
	n->value = NULL;
	n->type = 0;
}

void	init_new_cmd(t_cmd **cmd)
{
	t_cmd	*new;

	new = *cmd;
	new ->id = 0;
	new->argv = NULL;
	new->path = NULL;
	new->rdir = NULL;	
	new->next = NULL;
}
// void	init_new_rdir(t_minishell *ms, t_rdir **rdir)
// {
// 	t_rdir	*new;

// 	new = *rdir;
	
// 	new->type = NULL;	
// 	new->fd_rdir = NULL;
// 	new->next = NULL;
// }
