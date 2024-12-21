/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2024/12/20 19:30:19 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int get_type(char *token)
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
void creat_token(t_token **head,char *value, int type)
{
	t_token *new;
	t_token *last;
		
	new = malloc(sizeof (t_token));
	// if(!new)
	// 	return();
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
	t_token *head;
	char **split;
	int i;

	i = 0;
	split = ft_split(input, ' ');
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
    char *input;

    while (1)
	{
        input = readline("minishell$ ");
        if (!input)
		{ 
            printf("exit\n");
            break;
        }
        if (strcmp(input, "exit") == 0) {
            printf("exit\n");
            free(input); 
			break;
        }
        if (*input)
            add_history(input);
        printf("Entrada recibida: %s\n", input);
		lexer(input);
        free(input);
    }
}