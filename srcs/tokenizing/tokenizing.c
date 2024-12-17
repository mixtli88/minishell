/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2024/12/17 18:43:11 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int get_tokend(char *token)
{
	if (ft_strcmp(token, "|") == 0)
		return(TOKEN_PIPE);
	else if (ft_strncmp(token, ">", 1) == 0 ||  ft_strncmp(token, "<", 1) == 0)
		return(TOKEN_PIPE);
	else if (ft_strncmp(token, ";", 1) == 0)
		return(TOKEN_SEPARATOR);
	else if (ft_strncmp(token, "&", 1 ) == 0)
		return(TOKEN_BACKGROUND);
	else if (token[0] == '$')
		return(TOKEN_VARIABLE);
	else if (isalpha(token[0]))
		return(TOKEN_VARIABLE);
	else 
		return(TOKEN_PIPE);
	
}
t_token *creat_token(int type, char *value)
{
	t_token *token;
	token = malloc(sizeof (t_token));
	if(!token)
		return (NULL);
	
	token->type = type;
	token->value = ft_strdup(value);
	token->next = NULL;
	return (token);
	
}

void ft_list_token(t_token **head, char *str)
{
	t_token *token;
	t_token *last;
	
	token =  creat_token(get_tokend(str), str);
	if(*head == NULL)
		*head = token;
	else
	{
		last = head;
		while(last->next != NULL)
			last = last->next;
		last->next = token;
	}
}

void	tokenizing(int argc, char *argv[], char *envp[])
{
	t_token *list_token;
	
	int i;

	i = 0;
	ft_putstr_fd("tokenizing\n", STDOUT_FILENO);
	if (argc == 2)
	{
		argv = ft_split(argv[2], " ");	
		while(argv[i])
		{
			token(arg[i]);
			i++;
		}
	}	
}
