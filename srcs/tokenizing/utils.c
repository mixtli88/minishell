/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:00:16 by mabril            #+#    #+#             */
/*   Updated: 2025/01/14 13:14:56 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_count_char(char *str, char c)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
        if (*str == c) 
            count++;
        str++;     
    }
    return count;
}

int ft_isaspace(t_data **data )
{
	int found;
	t_data *d;
	
	d = *data;
	found = 0;	
	while(d->input[d->i] == ' ' || !d->input[d->i])
	{
		found = 1;
		if (d->buf_idx > 0)
		{
			d->buff[d->buf_idx]='\0';
			creat_token(data);
			d->buf_idx = 0;
		}
		if(d->input[d->i])
			d->i++;
		else
			break;
	}
	return(found);
}

int ft_isquote(t_data **data)
{
	t_data *d;
	
	d = *data;
	if(d->count_quote != 0 && d->input[d->i] != d->quote)
		return(0);
	while(d->input[d->i] == '"' || d->input[d->i] == '\'')
	{
		if(d->count_quote == 0)
		{
			d->quote = d->input[(d)->i];
			d->count_quote++;
		}
		else if(d->input[d->i] == d->quote )
			d->count_quote--;
		if(d->count_quote == 1 && d->input[d->i + 1] != d->quote)
		{
			d->i++;
			break;
		}
		d->i++;
	}
	return(d->count_quote);
}
void tok_is_cmd(t_data **data)
{
	t_data *d;
	t_token *token;
	
	d = *data;
	d->token_curr = d->tok_list;
	token = d->token_curr;
	if(!d->curr_cmd)
	{
		d->arg_c = 1;
		d->i = 0;
		d->curr_cmd = creat_cmd(data);
		while(token->next->type ==  CMD)
			d->arg_c++;
	}
	if(!d->curr_cmd->argv)
		d->curr_cmd->argv =(char **) malloc(sizeof(char*) * (d->arg_c + 1));
	d->curr_cmd->argv[d->i] = ft_strdup(token->value);
	if((d->i + 1) == d->arg_c)
		d->curr_cmd->argv[d->arg_c] = NULL;
	
}
void tok_is_redi(t_data **data)
{
	t_cmd *curr_cmd;
	t_token *token;
	
	curr_cmd = (*data)->curr_cmd;
	token = (*data)->token_curr;
	if(token->next->type != CMD) 
		error_free(data);
	if(ft_strncmp(token->value, "<", 1) == 0)
		curr_cmd->redi = SINGLE_IN; 
	else if(ft_strncmp(token->value, ">", 1) == 0)
		curr_cmd->redi = SINGLE_OUT; 
	else if(ft_strncmp(token->value, "<<", 2) == 0)
		curr_cmd->redi = DOUBLE_IN; 
	else if(ft_strncmp(token->value, ">>", 2) == 0)
		curr_cmd->redi = DOUBLE_OUT; 
	curr_cmd->valiu_redir = ft_strdup(token->next->value);
	
}
