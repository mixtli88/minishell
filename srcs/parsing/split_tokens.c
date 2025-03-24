/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:33:19 by mabril            #+#    #+#             */
/*   Updated: 2025/03/24 09:37:19 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_typecmd	type_token(char *token)
{
	if (ft_strcmp(token, "|") == 0)
		return (PIPE);
	else if (ft_strcmp(token, ">") == 0)
		return (REDIR);
	else if (ft_strcmp(token, "<") == 0)
		return (REDIR);
	else if (ft_strcmp(token, ">>") == 0)
		return (REDIR);
	else if (ft_strcmp(token, "<<") == 0)
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
	if (d->token_list == NULL)
		d->token_list = new;
	else
	{
		last = d->token_list;
		while (last->next != NULL)
			last = last->next;
		last->next = new;
	}
	d->token_cur = new;
	d->buf_idx = 0;
	d->buff[0] = '\0';
}

void 	read_aditional(t_minishell *ms)
{
	t_data	*d;
	char	*n_l;

	d = &ms->data;
	while (1)
	{
		n_l = ft_strdup("\n");
		(d->new_readline) = NULL;
		g_signal_status = 1;
		d->new_readline = readline(BLUE"> "RESET);
		if (g_signal_status == 2 || !d->new_readline)
		{
			if (!d->new_readline)
				error_quote();
			d->flag = -1;
			free(n_l);
			return ;
		}
		d->new_readline = ft_strcat(&n_l, &d->new_readline);
		d->new_inp = ft_strcat(&d->new_inp, &d->new_readline);
		d->count_quote = ft_count_char(d->new_inp, d->quote);
		if (d->count_quote % 2 != 0)
			break ;
	}
}

void	 check_quote(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if(d->count_quote == 0)
		return ;
	while (d->input[d->i] != d->quote )
	{
		if (ft_char_is_dolar(d->input[d->i]))
			ft_is_var(ms);
		else if (d->input[d->i])
			d->buff[d->buf_idx++] = d->input[d->i++];
		if (!d->input[d->i] && d->count_quote != 0)
		{
			read_aditional(ms);
			if (!d->new_inp)  
                return;
			d->input = ft_strcat(&d->input, &d->new_inp);
		}
		ft_isquote(ms);
		if (d->count_quote == 0 && (d->input[d->i] == '<'|| d->input[d->i] 
				== '>' || d->input[d->i] == ' '	|| d->input[d->i] == '\"' 
				|| d->input[d->i] == '\'' || !d->input[d->i]))
			break ;
	}
	d->in_quotes = 0;
}

bool	split_input(t_minishell *ms)
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
		else if (ft_char_is_dolar(d->input[d->i]) )
				ft_is_var(ms);
		else if (d->input[d->i] != ' ' && d->input[d->i] != '\0')
			d->buff[d->buf_idx++] = d->input[d->i++];
		if (d->flag == -1)
			return(false);
	}
	return(true);
}
