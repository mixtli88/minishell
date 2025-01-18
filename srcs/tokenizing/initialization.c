/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:15:33 by mabril            #+#    #+#             */
/*   Updated: 2025/01/18 18:48:54 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void init_data(t_minishell	*ms)
{
	t_data *d;
	
	d = &ms->data;
	d->input = NULL;
	d->buf_idx = 0;
	d->i = 0;
	d->quote = 0;
	d->new_readline = NULL;
	d->new_inp = NULL;
	d->path_w_slash = NULL;
    d->full_path = NULL;
    d->var = NULL;
    d->envp = NULL;
    d->buff[0] = '\0';
    d->var_buf[0] = '\0';
	d->tok_list = NULL;
	d->token_cur = NULL;
	d->cmd_list = NULL;
	d->cur_cmd = NULL;
}
void init_new_token(t_token **new)
{
	t_token *n;
	
	n = *new;
	n->value = NULL;
	n->type = 0;
}
void init_new_cmd(t_cmd **cmd)
{
	t_cmd *new;
	
	new = *cmd;
	new->argv = NULL;
	new->path = NULL;
	new->evrp = NULL;
	new->rdir = 0;
	new->fd_rdir = NULL;
	new->limiter = NULL;
	new->next = NULL;
}
