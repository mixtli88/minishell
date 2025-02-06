/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:33:19 by mabril            #+#    #+#             */
/*   Updated: 2025/02/06 05:06:20 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


t_type	type_token(char *token)
{
	if (ft_strncmp(token, "|", 1) == 0)
		return (PIPE);
	else if (ft_strncmp(token, ">", 1) == 0)
		return (REDIR);
	else if (ft_strncmp(token, "<", 1) == 0)
		return (REDIR);
	else
		return (CMD);
}

void	creat_token(t_minishell *ms)
{
	t_data	*d;
	t_token	*new;
	t_token	*last;

	d = &ms->data;
	last = NULL;
	new = malloc(sizeof(t_token));
	init_new_token(&new);
	new->value = ft_strdup(d->buff);
	new->type = type_token(d->buff);
	new->next = NULL;
	if (d->tok_list == NULL)
		d->tok_list = new;
	else
	{
		last = d->tok_list;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
}
char	*read_aditional(t_minishell *ms)
{
	t_data	*d;
	char	*n_l;

	n_l = ft_strdup("\n");
	d = &ms->data;
	while (1)
	{
		(d->new_readline) = NULL;
		d->new_readline = readline(">");
		if (!d->new_readline)
			error_quote();
		d->new_readline = ft_strcat(&n_l, &d->new_readline);
		d->new_inp = ft_strcat(&d->new_inp, &d->new_readline);
		d->count_quote = ft_count_char(d->new_inp, d->quote);
		if (d->count_quote % 2 != 0)
			break ;
	}
	return (d->new_inp);
}

void	check_quote(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	d->i++;
	while (d->input[d->i] != d->quote)
	{
		if (ft_char_is_dolar(d->input[d->i]))
			ft_is_var(ms);
		else if (d->input[d->i])
			d->buff[d->buf_idx++] = d->input[d->i++];
		if (!d->input[d->i] && d->count_quote != 0)
		{
			d->new_inp = read_aditional(ms);
			d->input = ft_strcat(&d->input, &d->new_inp);
		}
		ft_isquote(ms);
		if (d->count_quote == 0 && (d->input[d->i] == '<'
				|| d->input[d->i] == '>' || d->input[d->i] == ' '
				|| !d->input[d->i]))
			break ;
	}
}

void	split_input(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	d->i = 0;
	while (d->input[d->i] || d->buf_idx > 0)
	{
		if (ft_isaspace_inp(ms) || ft_is_rdir(ms) || ft_is_pipe(ms))
			d->buf_idx = 0;
		else if (ft_isquote(ms))
			check_quote(ms);
		else if (ft_char_is_dolar(d->input[d->i]))
			ft_is_var(ms);
		else if (d->input[d->i] != ' ' && d->input[d->i] != '\0')
			d->buff[d->buf_idx++] = d->input[d->i++];
	}
}
