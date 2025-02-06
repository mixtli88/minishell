/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:50:37 by mabril            #+#    #+#             */
/*   Updated: 2025/02/06 05:46:06 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	tok_is_pipe(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (!d->token_cur->next || !d->cur_cmd)
		error_syntax(ms);
	else if (d->token_cur->next->type != CMD)
		error_syntax(ms);
	else
	{
		d->cur_cmd = NULL;
		d->tok_tem = NULL;
	}
}

void	char_is_rdir(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (!d->token_cur->next || d->token_cur->next->type != CMD)
		error_syntax(ms);
	if (ft_strncmp(d->token_cur->value, "<", 1) == 0)
		d->cur_cmd->rdir = SINGLE_IN;
	else if (ft_strncmp(d->token_cur->value, ">", 1) == 0)
		d->cur_cmd->rdir = SINGLE_OUT;
	else if (ft_strncmp(d->token_cur->value, "<<", 2) == 0)
		d->cur_cmd->rdir = DOUBLE_IN;
	else if (ft_strncmp(d->token_cur->value, ">>", 2) == 0)
		d->cur_cmd->rdir = DOUBLE_OUT;
	d->cur_cmd->fd_rdir = ft_strdup(d->token_cur->next->value);
	d->token_cur = d->token_cur->next;
	d->token_cur = d->token_cur->next;
}

void	create_cmd(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	d->cur_cmd = creat_nod(ms);
	d->count_cmd += 1;
	d->arg_c = 1;
	d->i = 0;
	d->cur_cmd->id = d->count_cmd;
	if (d->token_cur->type == REDIR)
		char_is_rdir(ms);
	d->tok_tem = d->token_cur;
	if(!d->tok_tem)
		return;		
	while (d->tok_tem->next && d->tok_tem->next->type == CMD)
	{
		d->arg_c++;
		d->tok_tem = d->tok_tem->next;
	}
	if (!d->cur_cmd->argv)
	{
		d->cur_cmd->argv = (char **)malloc(sizeof(char *) * (d->arg_c + 1));
		d->cur_cmd->argv[d->arg_c] = NULL;
	}
	d->cur_cmd->argv[d->i++] = ft_strdup(d->token_cur->value);
}

void	tok_is_cmd(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	d->tok_tem = d->token_cur;
	if (!d->cur_cmd)
		create_cmd(ms);
	else
		d->cur_cmd->argv[d->i++] = ft_strdup(d->token_cur->value);
}

void	tok_is_redi(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (!d->token_cur->next || d->token_cur->next->type != CMD)
		error_syntax(ms);
	if (!d->cur_cmd)
		create_cmd(ms);
	else
		char_is_rdir(ms);
}


