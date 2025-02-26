/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:52:32 by mabril            #+#    #+#             */
/*   Updated: 2025/02/19 23:54:40 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_table(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		// str[i] = NULL;
		i++;
	}
	free(str);
	// str = NULL;
}

void	free_cmd_list(t_cmd **cmd_list)
{
	t_cmd	*tem;
	
	while ((*cmd_list))
	{
		tem = (*cmd_list);
		(*cmd_list) = (*cmd_list)->next;
		if (tem->argv)
			free_table(tem->argv);
		if (tem->path)
			free(tem->path);
		if (tem->rdir)
			free_rdir_list(tem->rdir);
		init_new_cmd(&tem);
		free(tem);
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
		head->value = NULL;
		head->type = 0;
		free(head);
		head = NULL;
		head = current;
	}
}

void	free_rdir_list(t_rdir *rdir_list)
{
	t_rdir *temp;

    while (rdir_list) 
	{
        temp = rdir_list;
        rdir_list = rdir_list->next;
        free(temp->fd_rdir);
        free(temp);
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
		if (isatty(STDIN_FILENO) == 0)
			dup2(ms->data.g_stdin, STDIN_FILENO);
		free_t_fd(ms);
	}
}
