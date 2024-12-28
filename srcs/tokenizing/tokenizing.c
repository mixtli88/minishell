/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2024/12/27 22:25:09 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void *ft_init_data(t_data **data)
{
	(*data)->buf_idx = 0;
	(*data)->i = 0;
	(*data)->input = NULL;
	(*data)->quote = NULL;
	(*data)->tok_list = NULL;
}
t_type get_type(char *token)
{
	if (ft_strncmp(token, "|", 1) == 0)
		return(PIPE);
	else if (ft_strncmp(token, ">", 1))
		return(REDIR_IN);
	else if (ft_strncmp(token, "<", 1) == 0)
		return(REDIR_IN);
	else if (ft_strncmp(token, ";", 1) == 0)
		return(SEPARATOR);
	else if (ft_strncmp(token, "&", 1 ) == 0)
		return(BACKGROUND);
	else if (token[0] == '$')
		return(VARIABLE);
	else if (ft_isalpha(token[0]))
		return(WORLD);
	else 
		return(TOKEN_INVALID);
	
}
void creat_token(t_token **head, char *value, int q_s, int q_d )
{
	t_token *new;
	t_token *last;
		
	new = malloc(sizeof (t_token));
	// if(!new)
	// 	return();
	last = NULL;
	new->value = ft_strdup(value);
	new->type = get_type(value);
	new->quote_single= q_s;
	new->quote_double = q_d;
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
	t_token *head;
	char **split;
	int i;

	i = 0;
	split = ft_split(input, ' ');
	while(split[i])
	{
		printf("s%d %s\n", i, split[i]);
		i++;
	}
	i = 0;
	while(split[i])
	{
		creat_token(&head, split[i], get_type(split[i]));
		i++;
	}
	free_table(split);
	return(head);
}

void ft_minishell_loop(void)
{
	t_data *data;
	
	data = ft_calloc(sizeof(t_data),1);
	ft_init_data(&data);
	
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
		data->tok_list = lexer(data->input);
	    free(data);
		data = NULL;
    }
}

        // printf("Entrada recibida: %s\n", data->input);
		// printf("1\n");
		// printf("2\n");
		// printf(" head %p\n", head);
		// printf(" act %p\n", act);