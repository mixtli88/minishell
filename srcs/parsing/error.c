/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:03:29 by mabril            #+#    #+#             */
/*   Updated: 2025/02/18 12:40:01 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	error_syntax(t_minishell *ms)
{
	t_data	*d;
	char	*strerror;

	strerror = NULL;
	d = &ms->data;
	if (!d->token_cur)
	{
		strerror = "|";
		ms->status = 2;
	}
	else if (!d->token_cur->next)
		strerror = "newline";
	else if (d->token_cur->next->type != CMD)
		strerror = d->token_cur->next->value;
	printf("mini: syntax error near unexpected token `%s'\n", strerror);
	d->flag = -1;
	return(false);
}

void	error_quote(void)
{
	ft_putstr_fd("minishell: unexpected EOF while looking for matching `\"\'\n", STDERR_FILENO);
	ft_putstr_fd("minishell: syntax error: unexpected end of file\n", STDERR_FILENO);
}
void	error_pipe(t_minishell *ms)
{
	ft_putstr_fd("mini: syntax error: unexpected end of file\n", STDERR_FILENO);
	free_data(ms);
	init_data(ms);
	exit(0);
}


