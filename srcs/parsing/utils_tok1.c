/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tok1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:00:16 by mabril            #+#    #+#             */
/*   Updated: 2025/03/24 08:45:07 by mike             ###   ########.fr       */
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
	if (d->input[d->i] == '|' || d->input[d->i] == '&' || d->input[d->i] == ';')
	{
		if (!d->token_list || d->token_cur->type == PIPE)
			error_syntax(ms);
		else
		{
			found = 1;
			if (d->buf_idx == 0)
				d->buff[d->buf_idx++] = d->input[d->i++];
			handle_pipe_input(ms);
			d->buff[d->buf_idx] = '\0';
			creat_token(ms);
		}
	}
	return (found);
}

int	ft_isquote(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (d->count_quote != 0 && d->input[d->i] != d->quote)
		return (0);
	if (d->input[d->i] == '\"' || d->input[d->i] == '\'')
	{
		if (d->count_quote == 0)
		{
			d->quote = d->input[d->i];
			d->count_quote++;
		}
		else if (d->input[d->i] == d->quote)
		{
			d->count_quote--;
			if((d->input[d->i + 1] == ' ' || d->input[d->i + 1] == '\0') && d->buff[0] == '\0')
				creat_token(ms);	
		}
		if_is_just_quote(ms);
		d->i++;
		return (d->in_quotes = 1, 1);
	}
	return (0);
}
