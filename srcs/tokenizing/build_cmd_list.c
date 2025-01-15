/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:50:37 by mabril            #+#    #+#             */
/*   Updated: 2025/01/14 19:05:16 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void tok_is_cmd(t_data **data)
{
	t_data *d;
	
	d = *data;
	if(!d->cur_cmd)
	{
		d->arg_c = 1;
		d->i = 0;
		d->cur_cmd = creat_cmd(data);
		while(d->token_cur->next->type ==  CMD)
			d->arg_c++;
	}
	if(!d->cur_cmd->argv)
		d->cur_cmd->argv =(char **) malloc(sizeof(char*) * (d->arg_c + 1));
	d->cur_cmd->argv[d->i] = ft_strdup(d->token_cur->value);
	if((d->i + 1) == d->arg_c)
		d->cur_cmd->argv[d->arg_c] = NULL;
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
		d->cur_cmd->redi = SINGLE_IN; 
	else if(ft_strncmp(d->token_cur->value, ">", 1) == 0)
		d->cur_cmd->redi = SINGLE_OUT; 
	else if(ft_strncmp(d->token_cur->value, "<<", 2) == 0)
		d->cur_cmd->redi = DOUBLE_IN; 
	else if(ft_strncmp(d->token_cur->value, ">>", 2) == 0)
		d->cur_cmd->redi = DOUBLE_OUT; 
	d->cur_cmd->valiu_redir = ft_strdup(d->token_cur->next->value);
	d->token_cur = d->token_cur->next;
}