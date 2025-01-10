/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:03:29 by mabril            #+#    #+#             */
/*   Updated: 2024/12/20 18:39:16 by mabril           ###   ########.fr       */
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

void	error_free(t_token **head, char **av, bool flag_split)
{
	if (*head)
		free_list(*head);
	if (flag_split)
		free_table(av);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_table(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_list(t_token *head)
{
	t_token	*current;

	current = head->next;
	while (head)
	{
		current = head->next;
		free(head);
		head = current;
	}
}