/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:03:29 by mabril            #+#    #+#             */
/*   Updated: 2025/01/15 22:32:00 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	error_syntax(char *str)
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
		current = head->next;
		if(head->argv)
			free_table(head->argv);
		if(head->path)
			free(head->path);
		if(head->fd_rdir)
			free(head->fd_rdir);
		if(head->limiter)
			free(head->limiter);	
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
		current = head->next;
		if(head->value)
			free(head->value);
		free(head);
		head = current;
	}
}
void	free_data(t_data **data)
{
	if(*data)
	{
		if((*data)->input)
			free((*data)->input);
		if((*data)->new_readline)
			free((*data)->new_readline);
		if((*data)->new_inp)
			free((*data)->new_inp);
		if((*data)->path_w_slash)
			free((*data)->path_w_slash);
		if((*data)->full_path)
			free((*data)->full_path);
		if((*data)->tok_list)
			free_token_list((*data)->tok_list);
		free(*data);
		(*data) = NULL;
	}
}
void	error_free(t_data **data)
{
	
	if ((*data)->cmd_list)
		free_cmd_list(&(*data)->cmd_list);
	if (*data)
		free_data(data);		
	// write(2, "Error\n", 6);
	// exit(1);
}