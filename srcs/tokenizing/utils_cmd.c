/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:50:37 by mabril            #+#    #+#             */
/*   Updated: 2025/01/15 17:25:27 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void tok_is_cmd(t_data **data)
{
	t_data *d;
	t_token *tok_tem;
	
	d = *data;
	tok_tem = d->token_cur;
	if(!d->cur_cmd)
	{
		d->arg_c = 1;
		d->i = 0;
		d->cur_cmd = creat_cmd(data);
		while(tok_tem->next && tok_tem->next->type ==  CMD)
		{
			d->arg_c++;
			tok_tem = tok_tem->next;
		}
	}
	if(!d->cur_cmd->argv)
	{
		d->cur_cmd->argv =(char **) malloc(sizeof(char*) * (d->arg_c + 1));
		d->cur_cmd->argv[d->arg_c] = NULL;
	}
	d->cur_cmd->argv[d->i] = ft_strdup(d->token_cur->value);
	if(d->i == 0)
		find_path(data);
}

void tok_is_pipe(t_data **data)
{

	if(!(*data)->cur_cmd)
		error_free(data);
	else
		(*data)->cur_cmd = NULL;
}

void tok_is_redi(t_data **data)
{
	t_data *d;
	
	d = *data;
	if(d->token_cur->next->type != CMD) 
		error_free(data);
	if(ft_strncmp(d->token_cur->value, "<", 1) == 0)
		d->cur_cmd->rdir = SINGLE_IN; 
	else if(ft_strncmp(d->token_cur->value, ">", 1) == 0)
		d->cur_cmd->rdir = SINGLE_OUT; 
	else if(ft_strncmp(d->token_cur->value, "<<", 2) == 0)
		d->cur_cmd->rdir = DOUBLE_IN; 
	else if(ft_strncmp(d->token_cur->value, ">>", 2) == 0)
		d->cur_cmd->rdir = DOUBLE_OUT; 
	d->cur_cmd->fd_rdir = ft_strdup(d->token_cur->next->value);
	d->token_cur = d->token_cur->next;
}