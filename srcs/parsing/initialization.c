/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:15:33 by mabril            #+#    #+#             */
/*   Updated: 2025/03/24 08:52:31 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_data(t_minishell *ms)
{
	ms->data.input = NULL;
	ms->data.buf_idx = 0;
	ms->data.i = 0;
	ms->data.count_cmd = 0;
	ms->data.quote = 0;
	ms->data.count_quote = 0;
	ms->data.new_readline = NULL;
	ms->data.new_inp = NULL;
	ms->data.full_path = NULL;
	ms->data.var = NULL;
	ms->data.envp = NULL;
	ms->data.var = NULL;
	ms->data.var_buf[0] = '\0';
	ms->data.token_list = NULL;
	ms->data.token_cur = NULL;
	ms->data.token_tem = NULL;
	ms->data.token_last = NULL;
	ms->data.cmd_list = NULL;
	ms->data.cur_cmd = NULL;
	ms->data.path = NULL;
	ms->data.last_slash = NULL;
	ms->data.flag = 0;	
	if (g_signal_status == 2)
		ms->status = 130;
	g_signal_status = 1;
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
