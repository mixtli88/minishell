/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:03:29 by mabril            #+#    #+#             */
/*   Updated: 2025/01/18 18:27:10 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	error_sy(char *str)
{
	if ((*str == '+' || *str == '-') && ft_strlen(str) == 1)
		return (1);
	if (!(*str == '+' || *str == '-' || (*str >= '0'
				&& *str <= '9')) || !*str)
		return (1);
	if ((*str == '+' || *str == '-' || (*str >= '0'
				&& *str <= '9')))
	{
		while (*++str)
			if (!(*str >= '0' && *str <= '9') || *str == '#')
				return (1);
	}
	return (0);
}

void	free_table(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_cmd_list(t_cmd **cmd_list)
{
	t_cmd	*current;
	t_cmd *head;

	head = *cmd_list;
	while (head)
	{
		if(head->next)
			current = head->next;
		else
			current = NULL;
		if(head->argv)
			free_table(head->argv);
		if(head->path)
			free(head->path);
		if(head->evrp)
			free(head->evrp);
		if(head->fd_rdir)
			free(head->fd_rdir);
		if(head->limiter)
			free(head->limiter);
		init_new_cmd(&head);
		free(head);
		head = NULL;
		head = current;
	}
}
void	free_token_list(t_token *token_list)
{
	t_token	*current;
	t_token *head;

	head = token_list;
	current = head->next;
	while (head)
	{
		if(head->next)
			current = head->next;
		else
			current = NULL;
		if(head->value)
			free(head->value);		
		init_new_token(&head);
		free(head);
		head = NULL;
		head = current;
	}
}

void	free_data(t_minishell *ms)
{
	t_data *d;
	
	d = &ms->data;	
	if(d)
	{
		if(d->input)
			free(d->input);
		if(d->new_readline)
			free(d->new_readline);
		if(d->new_inp)
			free(d->new_inp);
		if(d->path_w_slash)
			free(d->path_w_slash);
		if(d->full_path)
			free(d->full_path);
		if(d->tok_list)
			free_token_list(d->tok_list);
		if (d->cmd_list)
			free_cmd_list(&d->cmd_list);
		init_data(ms);
		d = NULL;
	}
		printf("\n");
		ft_minishell_loop(ms);
}

void error_syntax(t_minishell *ms)
{
	t_data *d;
	char *strerror;
	
	d = &ms->data;
	strerror = NULL;
	if(!d->token_cur->next )
	{
		strerror = "newline";
	}
	else
	{
		if(d->token_cur->next->type != CMD)
			strerror = d->token_cur->next->value;
	}
	printf("minishell: syntax error near unexpected token `%s'", strerror);
	free_data(ms);	
}

void error_path_cmd(t_minishell *ms)
{
	t_data *d;
	
	d = &ms->data;
	printf("minishell: %s: command not found\n", d->cur_cmd->argv[0]);
	free_data(ms);	
}
void error_quote(t_minishell *ms)
{
	printf("Error, for closing quote\n");
	free_data(ms);
}

