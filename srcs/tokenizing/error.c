/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:03:29 by mabril            #+#    #+#             */
/*   Updated: 2025/01/13 12:06:22 by mike             ###   ########.fr       */
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
	current = head->next;
	while (head)
	{
		free_table(head->argv);
		current = head->next;
		free(head);
		head = current;
	}
}
void	free_token_list(t_data **data)
{
	t_token	*current;
	t_token *head;

	head = (*data)->tok_list;
	current = head->next;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}
void	free_data(t_data **data)
{
	if(*data)
	{
		if((*data)->tok_list)
			free_token_list((*data)->tok_list);
		free(*data);
	}
}
void	error_free(t_data **data, t_cmd **cmd_list)
{
	int i;
	t_cmd *tem;

	if (*cmd_list)
		free_list(*cmd_list);
	if (*data)
		free_data(data);		
	write(2, "Error\n", 6);
	exit(1);
}