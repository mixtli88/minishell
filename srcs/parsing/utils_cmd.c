/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:50:37 by mabril            #+#    #+#             */
/*   Updated: 2025/03/24 10:02:40 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void	tok_is_pipe(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (!d->token_cur->next || !d->cur_cmd || (d->token_cur->next->type != CMD && d->token_cur->next->type != REDIR))
		error_syntax(ms);
	else
	{
		d->cur_cmd = NULL;
		d->token_tem = NULL;
	}
	d->token_cur = d->token_cur->next;
}
