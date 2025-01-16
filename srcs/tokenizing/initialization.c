/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:15:33 by mabril            #+#    #+#             */
/*   Updated: 2025/01/15 22:12:28 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void init_data(t_data **data)
{
	t_data *d;
	
	d = *data;
	d->buf_idx = 0;
	d->i = 0;
	d->quote = 0;
	d->new_inp = NULL;
	d->new_readline = NULL;
	d->path_w_slash = NULL;
    d->full_path = NULL;
	if(!d->tok_list)
		d->tok_list = NULL;
	if(!d->cmd_list)
		d->cmd_list = NULL;
}
void init_new_token(t_data **data, t_token **new)
{
	t_data *d;
	t_token *n;
	
	d = *data;
	n = *new;
	n->value = ft_strdup(d->buff);
	n->type = type_token(d->buff);
	if(d->quote == '"')
		n->quote = 2;
	else if(d->quote == '\'')
		n->quote = 1;	
	else
		n->quote = 0;
}
void init_new_cmd(t_cmd **cmd)
{
	t_cmd *new;
	
	new = *cmd;
	new->argv = NULL;
	new->path = NULL;
	new->evr = NULL;
	new->rdir = 0;
	new->fd_rdir = NULL;
	new->limiter = NULL;	
}
