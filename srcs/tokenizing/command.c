/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:06:02 by mabril            #+#    #+#             */
/*   Updated: 2025/01/10 21:22:29 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void creat_cmd(t_cmd **cmd_lis, t_data **data)
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
	if(cmd_lis == NULL)
		cmd_lis = new;
	else
	{
		last = cmd_lis;
		while(last->next != NULL)
			last = last->next;
		last->next = new;
	}	
}



t_cmd *buil_cmd_list(t_data **data)
{
	t_token *tokens;
	t_cmd *cmd_list;
	t_cmd *current_cmd;
	int arg_c;
	int value_c;
	int i;
	
	tokens = (*data)->tok_list;
	cmd_list = NULL;
	current_cmd = NULL;
	i = 0;
	// ft_init_data(data);
	while(tokens)
	{
		if(tokens && tokens->type == CMD)
		{
			if(!cmd_list)
			{
				creat_cmd(&cmd_list, data);
				if(tokens->type == CMD)
					while(tokens->next->type ==  CMD)
						arg_c++;
			}
			if(!cmd_list->argv)
				cmd_list->argv = malloc(sizeof(char*) * arg_c +1);
			cmd_list->argv[i] = ft_strdup(tokens->value);
		}
		else if( tokens->type == PIPE )
		{
			current_cmd = cmd_list;
			if(!current_cmd)
				error_syntax();
			while(current_cmd->next != NULL)
				current_cmd = current_cmd->next;
			creat_cmd(&cmd_list, data);
			current_cmd->output_fd = current_cmd->next->input_fd;
		}
		else if ( tokens->type ==  REDIR)
		{
			if((tokens->value == '>' || tokens->value == '<' || tokens->value == '>>' || tokens->value == '<<' )&& tokens->next->type != CMD) 
				cmd_list->output_fd == ft_strdup(tokens->next->value)
			if(tokens->value == '<') 
			
		}




	
		i++;
		tokens = tokens->next;	
	}
}