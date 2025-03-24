/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:03:29 by mabril            #+#    #+#             */
/*   Updated: 2025/03/24 10:40:17 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	error_syntax(t_minishell *ms)
{
	t_data	*d;
	char	*strerror;

	strerror = NULL;
	d = &ms->data;
	if (d->token_cur && d->token_cur->type == PIPE)
		strerror =  "|";
	else if (!d->token_cur)
	{
		d->buff[d->buf_idx++] = d->input[d->i++];
		if(d->input[d->i -1] == d->input[d->i])
			d->buff[d->buf_idx++] = d->input[d->i++];
		d->buff[d->buf_idx] = '\0';
		strerror = d->buff;
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


