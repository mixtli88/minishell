/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:52:32 by mabril            #+#    #+#             */
/*   Updated: 2025/01/30 13:58:51 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	t_cmd	*head;

	head = *cmd_list;
	while (head)
	{
		if (head->next)
			current = head->next;
		else
			current = NULL;
		if (head->argv)
			free_table(head->argv);
		if (head->path)
			free(head->path);
		if (head->fd_rdir)
			free(head->fd_rdir);
		init_new_cmd(&head);
		free(head);
		head = NULL;
		head = current;
	}
}

void	free_token_list(t_token *token_list)
{
	t_token	*current;
	t_token	*head;

	head = token_list;
	current = head->next;
	while (head)
	{
		if (head->next)
			current = head->next;
		else
			current = NULL;
		if (head->value)
			free(head->value);
		init_new_token(&head);
		free(head);
		head = NULL;
		head = current;
	}
}

void	free_data(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (d)
	{
		if (d->input)
			free(d->input);
		if (d->new_readline)
			free(d->new_readline);
		if (d->new_inp)
			free(d->new_inp);
		if (d->full_path)
			free(d->full_path);
		if (d->tok_list)
			free_token_list(d->tok_list);
		if (d->cmd_list)
			free_cmd_list(&d->cmd_list);
		init_data(ms);
		d = NULL;
	}
}
