/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:50:37 by mabril            #+#    #+#             */
/*   Updated: 2025/02/13 13:24:21 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	tok_is_pipe(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (!d->token_cur->next || !d->cur_cmd || d->token_cur->next->type != CMD)
		error_syntax(ms);
	else
	{
		d->cur_cmd = NULL;
		d->tok_tem = NULL;
	}
	d->token_cur = d->token_cur->next;
}

void	value_rdir(t_minishell *ms, t_rdir **new)
{
	t_data	*d;
	
	d = &ms->data;
	if (ft_strncmp(d->token_cur->value, "<", 1) == 0)
		(*new)->type = SINGLE_IN;
	else if (ft_strncmp(d->token_cur->value, ">", 1) == 0)
		(*new)->type = SINGLE_OUT;
	else if (ft_strncmp(d->token_cur->value, "<<", 2) == 0)
		(*new)->type = DOUBLE_IN;
	else if (ft_strncmp(d->token_cur->value, ">>", 2) == 0)
		(*new)->type = DOUBLE_OUT;
	
}

void	create_cmd(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if(!d->cur_cmd)
	{
		d->cur_cmd = creat_nod(ms);
		d->count_cmd += 1;
		d->arg_c = 0;
		d->i = 0;
		d->cur_cmd->id = d->count_cmd;
	}
	d->tok_tem = d->token_cur;
	if(!d->tok_tem)
		return;		
	while (d->tok_tem && d->tok_tem->type == CMD)
	{
		d->arg_c++;
		d->tok_tem = d->tok_tem->next;
	}
	if (!d->cur_cmd->argv && d->arg_c != 0)
	{
		d->cur_cmd->argv = (char **)malloc(sizeof(char *) * (d->arg_c + 1));
		d->cur_cmd->argv[d->arg_c] = NULL;
		d->cur_cmd->argv[d->i++] = ft_strdup(d->token_cur->value);
	}
}

void	tok_is_cmd(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	d->tok_tem = d->token_cur;
	if (!d->cur_cmd || !d->cur_cmd->argv)
		create_cmd(ms);
	else
		d->cur_cmd->argv[d->i++] = ft_strdup(d->token_cur->value);
	d->token_cur = d->token_cur->next;
}

void	tok_is_redi(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (!d->token_cur->next || d->token_cur->next->type != CMD)
		error_syntax(ms);
	else 
	{
		if (!d->cur_cmd)
			create_cmd(ms);
		creat_nod_rdir(ms);
		d->token_cur = d->token_cur->next;
		d->token_cur = d->token_cur->next;
	}
}


