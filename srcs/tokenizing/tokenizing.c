/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2025/01/17 23:27:59 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_type type_token(char *token)
{
	if (ft_strncmp(token, "|", 1) == 0)
		return(PIPE);
	else if (ft_strncmp(token, ">", 1) == 0)
		return(REDIR);
	else if (ft_strncmp(token, "<", 1) == 0)
		return(REDIR);
	else if (ft_strncmp(token, ">>", 1) == 0)
		return(REDIR);
	else if (ft_strncmp(token, "<<", 1) == 0)
		return(REDIR);
	else if (token[0] == '$')
		return(VARIABLE);
	else 
		return(CMD);
	
}
void creat_token(t_data **data)
{
	t_data *d;
	t_token *new;
	t_token *last;
	
	d = *data;	
	last = NULL;
	new = malloc(sizeof (t_token));
	init_new_token(data, &new);
	new->next = NULL;
	if(d->tok_list == NULL)
		d->tok_list = new;
	else
	{
		last = d->tok_list;
		while(last->next != NULL)
			last = last->next;
		last->next = new;
	}	
}

void lexer(t_minishell	*ms, t_data **data)
{
	t_token *tok_curr;
	t_cmd *cmd_curr;
	
	// int i = 0 ;
	init_data(data);
	split_input(ms, data);
	buil_cmd_list(ms, data);
	cmd_curr = (*data)->cmd_list;
	tok_curr = (*data)->tok_list->next;
	
	while (tok_curr)
	{
		printf("%s ", tok_curr->value);
		tok_curr = tok_curr->next;
	} 
	// printf("\n\n***** list.token **** \n");
	
	// int j = 0;
	// while (cmd_curr)
	// {	
	// 	i = 0;
	// 	printf("\ncmd [%d] \narg -> = {", j);
	// 	while (cmd_curr->argv[i])
	// 	{
	// 		printf(" \"%s\"", cmd_curr->argv[i]);
	// 		if(cmd_curr->argv[i + 1])
	// 			printf(",");
	// 		else
	// 			printf(" }\n");
	// 		i++;
	// 	}
	// 	printf("fd = { \"%s\" }\n", cmd_curr->fd_rdir);
	// 	printf("redi = {%d}\n", cmd_curr->rdir);
	// 	cmd_curr = cmd_curr->next;
	// 	j++;
	// }
	printf("\n");
}

void ft_minishell_loop(t_minishell	*ms)
{
	t_data *data;
	
	data = NULL;
    while (1)
	{
		if(data == NULL)
			data = ft_calloc(sizeof(t_data),1);
		data->env = ms->envp;
        data->input = readline("minishell$ ");
        if (!data->input)
            break;
        if (strcmp(data->input, "exit") == 0) 
		{
            printf("exit\n");
            error_free(ms, &data);
			break;
        }
        if (data->input)
            add_history(data->input);
		// init_data(&data);
		lexer(ms, &data);
		// ex(&ms, data->cmd_list);
	    if(data)
			error_free(ms, &data);
    }
}

