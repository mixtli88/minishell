/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:03:29 by mabril            #+#    #+#             */
/*   Updated: 2025/01/19 11:57:46 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_syntax(t_minishell *ms)
{
	t_data	*d;
	char	*strerror;

	d = &ms->data;
	strerror = NULL;
	if (!d->token_cur->next)
	{
		strerror = "newline";
	}
	else
	{
		if (d->token_cur->next->type != CMD)
			strerror = d->token_cur->next->value;
	}
	printf("minishell: syntax error near unexpected token `%s'", strerror);
	free_data(ms);
	strerror = NULL;
	ft_minishell_loop(ms);
}

void	error_path_cmd(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	printf("minishell: %s: command not found", d->token_cur->value);
	free_data(ms);
	ft_minishell_loop(ms);
}

void	error_quote(t_minishell *ms)
{
	printf("Error, for closing quote");
	free_data(ms);
	ft_minishell_loop(ms);
}
