/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2024/12/22 18:23:31 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_type get_type(char *token)
{
	if (ft_strncmp(token, "|", 1) == 0)
		return(TOKEN_PIPE);
	else if (ft_strncmp(token, ">", 1) == 0 ||  ft_strncmp(token, "<", 1) == 0)
		return(TOKEN_REDIRECTION);
	else if (ft_strncmp(token, ";", 1) == 0)
		return(TOKEN_SEPARATOR);
	else if (ft_strncmp(token, "&", 1 ) == 0)
		return(TOKEN_BACKGROUND);
	else if (token[0] == '$')
		return(TOKEN_VARIABLE);
	else if (ft_isalpha(token[0]))
		return(TOKEN_COMMAND);
	else 
		return(TOKEN_INVALID);
	
}
void creat_token(t_token **head, char *value, t_type type)
{
	t_token *new;
	t_token *last;
		
	new = malloc(sizeof (t_token));
	// if(!new)
	// 	return();
	last = NULL;
	new->value = ft_strdup(value);
	new->type = type;
	new->next = NULL;
	if(*head == NULL)
		*head = new;
	else
	{
		last = *head;
		while(last->next != NULL)
			last = last->next;
		last->next = new;
	}	
}

t_token *lexer(char *input)
{
	t_token *head= NULL;
	t_token *act;
	char **split;
	int i;

	i = 0;
	split = ft_split(input, ' ');
	while(split[i])
	{
		printf("s%d %s\n",i, split[i]);
		i++;
	}
	// printf(" head %p\n", head);
	// printf(" act %p\n", act);
	i = 0;
	while(split[i])
	{
		printf("1\n");
		creat_token(&head, split[i], get_type(split[i]));
		printf("2\n");
		// printf(" head %p\n", head);
		// printf(" act %p\n", act);
		
		
		i++;
	}
	act = head;
	// printf("value new token %s\n", new->value);
	while(act)
	{
		printf("token = %s\n", act->value);
		act = act->next;
	}	
	free_table(split);
	return(head);
}

void ft_minishell_loop(void)
{
	t_data *data;
	data = ft_calloc(sizeof(t_data),1);
	
    while (1)
	{
		if(data == NULL)
			data = ft_calloc(sizeof(t_data),1);
        data->input = readline("minishell$ ");
        if (!data->input)
            break;
        if (strcmp(data->input, "exit") == 0) 
		{
            printf("exit\n");
            free(data); 
			break;
        }
        if (*data->input)
            add_history(data->input);
        printf("Entrada recibida: %s\n", data->input);
		data->tok_list = lexer(data->input);
	    free(data);
		data = NULL;
    }
}