/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:03:29 by mabril            #+#    #+#             */
/*   Updated: 2025/02/06 05:48:01 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_syntax(t_minishell *ms)
{
	t_data	*d;
	char	*strerror;

	strerror = NULL;
	d = &ms->data;
	if (!d->token_cur)
		strerror = "|";
	else if (ft_strncmp(d->token_cur->value, "|", 1) == 0)
		strerror = d->token_cur->value;
	else if (!d->token_cur->next)
		strerror = "newline";
	else if (d->token_cur->next->type != CMD)
		strerror = d->token_cur->next->value;
	printf("minishell: syntax error near unexpected token `%s'\n", strerror);
	ft_minishell_loop(ms);
}

void	error_quote(void)
{
	
	ft_putstr_fd("minishell: Error, for closing quote\n", STDERR_FILENO);
}


