/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tok1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:00:16 by mabril            #+#    #+#             */
/*   Updated: 2025/02/06 05:07:44 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_char_is_dolar(char i)
{
	char	c;

	c = '$';
	if (i == c)
		return (1);
	return (0);
}

int	ft_count_char(char *str, char c)
{
	int	count;

	count = 0;
	if (!str)
		return (count);
	while (*str != '\0')
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	ft_isaspace_inp(t_minishell *ms)
{
	int		found;
	t_data	*d;

	d = &ms->data;
	found = 0;
	while (ft_isspace(d->input[d->i]) || !d->input[d->i])
	{
		found = 1;
		if (d->buf_idx > 0)
		{
			d->buff[d->buf_idx] = '\0';
			creat_token(ms);
			d->buf_idx = 0;
		}
		if (!d->input[d->i])
			break ;
		d->i++;
	}
	return (found);
}

int	ft_is_pipe(t_minishell *ms)
{
	t_data	*d;
	int		found;

	d = &ms->data;
	found = 0;
	if (d->input[d->i] == '|')
	{
		if (!d->tok_list)
			error_syntax(ms);
		found = 1;
		if (d->buf_idx == 0)
			d->buff[d->buf_idx++] = d->input[d->i++];
		handle_pipe_input(ms);
		d->buff[d->buf_idx] = '\0';
		creat_token(ms);
	}
	return (found);
}

int	ft_isquote(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (d->count_quote != 0 && d->input[d->i] != d->quote)
		return (0);
	while (d->input[d->i] == '"' || d->input[d->i] == '\'')
	{
		if (d->count_quote == 0)
		{
			d->quote = d->input[d->i];
			d->count_quote++;
		}
		else if (d->input[d->i] == d->quote)
			d->count_quote--;
		if_is_just_quote(ms);
		if (d->count_quote == 1 && d->input[d->i + 1] != d->quote)
			break ;
		d->i++;
	}
	return (d->count_quote);
}
