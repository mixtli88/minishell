/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2025/01/19 11:55:08 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_type	type_token(char *token)
{
	if (ft_strncmp(token, "|", 1) == 0)
		return (PIPE);
	else if (ft_strncmp(token, ">", 1) == 0)
		return (REDIR);
	else if (ft_strncmp(token, "<", 1) == 0)
		return (REDIR);
	else
		return (CMD);
}

void	creat_token(t_minishell *ms)
{
	t_data	*d;
	t_token	*new;
	t_token	*last;

	d = &ms->data;
	last = NULL;
	new = malloc(sizeof(t_token));
	init_new_token(&new);
	new->value = ft_strdup(d->buff);
	new->type = type_token(d->buff);
	new->next = NULL;
	if (d->tok_list == NULL)
		d->tok_list = new;
	else
	{
		last = d->tok_list;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}

// void	lexer(t_minishell *ms)
// {
// 	t_token	*tok_curr;
// 	t_data	*d;

// 	d = &ms->data;
// 	split_input(ms);
// 	buil_cmd_list(ms);
// 	printf("\n");
// }

void	ft_minishell_loop(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	while (1)
	{
		init_data(ms);
		d->envp = ms->envp;
		d->input = readline("minishell$ ");
		if (!d->input)
			break ;
		if (strcmp(d->input, "exit") == 0)
		{
			printf("exit\n");
			free_data(ms);
			exit(1);
		}
		if (d->input)
			add_history(d->input);
		lexer(ms);
		if (d)
			free_data(ms);
	}
}

void	lexer(t_minishell *ms)
{
	t_token	*tok_curr;
	t_data	*d;
	t_cmd	*cmd_curr;
	int		i;
	int		j;

	d = &ms->data;
	i = 0;
	split_input(ms);
	buil_cmd_list(ms);
	cmd_curr = d->cmd_list;
	tok_curr = d->tok_list;
	printf("\n");
	printf("\n");
	while (tok_curr)
	{
		printf("%s ", tok_curr->value);
		tok_curr = tok_curr->next;
	}
	printf("\n\n***** list.token **** \n");
	j = 0;
	while (cmd_curr)
	{
		i = 0;
		printf("\ncmd [%d] \narg -> = {", j);
		while (cmd_curr->argv[i])
		{
			printf(" \"%s\"", cmd_curr->argv[i]);
			if (cmd_curr->argv[i + 1])
				printf(",");
			else
				printf(" }\n");
			i++;
		}
		printf("fd = { \"%s\" }\n", cmd_curr->fd_rdir);
		printf("redi = {%d}\n", cmd_curr->rdir);
		cmd_curr = cmd_curr->next;
		j++;
	}
	// printf("\n");
}