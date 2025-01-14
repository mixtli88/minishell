/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:06:02 by mabril            #+#    #+#             */
/*   Updated: 2025/01/13 21:01:38 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


t_cmd *creat_cmd(t_cmd **cmd_lis, t_data **data)
{
	t_cmd *new;
	t_cmd *last;
	t_token *tokens;
	
	tokens = (*data)->tok_list;
	new = malloc(sizeof (t_cmd));
	last = NULL;
	// new->value = ft_strdup(d->buff);
	// new->type = type_token(d->buff);

	new->next = NULL;
	if(*cmd_lis == NULL)
		*cmd_lis = new;
	else
	{
		last = *cmd_lis;
		while(last->next != NULL)
			last = last->next;
		last->next = new;
	}
	return(new);
}



t_cmd *buil_cmd_list(t_data **data)
{
	t_token *tokens;
	t_cmd *cmd_list;
	t_cmd *current_cmd;
	int arg_c;
	int value_c;
	int i;
	
	
	value_c = 0;
	tokens = (*data)->tok_list;
	cmd_list = NULL;
	current_cmd = NULL;
	// ft_init_data(data);
	while(tokens)
	{
		if(tokens && tokens->type == CMD)
		{
			if(!current_cmd)
			{
				arg_c = 1;
				i = 0;
				current_cmd = creat_cmd(&cmd_list, data);
				while(tokens->next->type ==  CMD)
					arg_c++;
			}
			if(!current_cmd->argv)
				current_cmd->argv =(char **) malloc(sizeof(char*) * arg_c +1);
			current_cmd->argv[i] = ft_strdup(tokens->value);
			if((i + 1) == arg_c)
				current_cmd->argv[arg_c] = NULL;
				 
		}
		else if( tokens->type == PIPE )
		{
			if(!current_cmd)
				error_free(data, &cmd_list);
			else
				current_cmd = NULL;
		}		
		else if (tokens->type ==  REDIR)
		{
			if(tokens->next->type != CMD) 
				error_free(data, &cmd_list);
			if(ft_strncmp(tokens->value, "<", 1) == 0)
				current_cmd->redi = SINGLE_IN; 
			else if(ft_strncmp(tokens->value, ">", 1) == 0)
				current_cmd->redi = SINGLE_OUT; 
			else if(ft_strncmp(tokens->value, "<<", 2) == 0)
				current_cmd->redi = DOUBLE_IN; 
			else if(ft_strncmp(tokens->value, ">>", 2) == 0)
				current_cmd->redi = DOUBLE_OUT; 
			current_cmd->valiu_redir = ft_strdup(tokens->next->value);
			tokens = tokens->next;	
		}
		i++;
		tokens = tokens->next;	
	}
	return(cmd_list);
}
