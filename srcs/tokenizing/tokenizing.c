/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2025/01/23 19:04:31 by fwu              ###   ########.fr       */
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

void	lexer(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	split_input(ms);
	buil_cmd_list(ms);
	// print_cmd(ms);
	// printf("\n");
}

void	ft_minishell_loop(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	while (1)
	{
		free_data(ms);
		init_data(ms);
		d->envp = ms->envp;
		d->input = readline("mini-3.1$ ");
		if (!d->input)
			break ;
		if (d->input)
			add_history(d->input);
		lexer(ms);
		pipex(ms);
	}
}

void	print_cmd(t_minishell *ms)
{
	t_token		*tok_curr;
	t_cmd		*cmd_curr;
	t_data		*d;
	
	int			i;
	int			j;

	d = &ms->data;
	cmd_curr = d->cmd_list;
	tok_curr = d->tok_list;
	printf("\n");
	while (tok_curr)
	{
		printf("%s ", tok_curr->value);
		tok_curr = tok_curr->next;
	}
	printf("\n");
	printf("\n\n***** list.token **** \n\n");
	j = 0;
	while (cmd_curr)
	{
		i = 0;
		printf("t_cmd *node [%d] = {\n", cmd_curr->id);
		if (cmd_curr->argv)
		{
			printf("    .argv = {");
			while (cmd_curr->argv[i])
			{
				printf(" \"%s\"", cmd_curr->argv[i]);
				if (cmd_curr->argv[i + 1])
					printf(", ");
				else
					printf(" },\n");
				i++;
			}
		}
		else
			printf("    .argv = { NULL },\n");
		printf("    .path = \"%s\",\n", cmd_curr->path);
		const char	*redir_str[] = {"NOT", "SINGLE_IN", "SINGLE_OUT", "DOUBLE_IN",
		"DOUBLE_OUT"};
		printf("    .rdir = %s,\n", redir_str[cmd_curr->rdir]);
		printf("    .fd_rdir = \"%s\",\n", cmd_curr->fd_rdir);
		printf("    .next = %s\n", cmd_curr->next ? "Non-null" : "NULL");
		printf("\n");
		cmd_curr = cmd_curr->next;
		j++;
	}
}
