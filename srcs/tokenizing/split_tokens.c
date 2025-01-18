/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:33:19 by mabril            #+#    #+#             */
/*   Updated: 2025/01/17 23:28:27 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *read_aditional(t_data **data)
{
	t_data *d;
	
	d = *data;
	while(1)
	{
		d->new_readline = readline(">");
		if(!d->new_readline)
		{	error_quote()
			printf("Error, for closing quote\n");
			if(d->new_inp)
			{
				free(d->new_inp);
				d->new_inp = NULL;
			}
			return(NULL);
		}
		d->new_inp = ft_strcat(&d->new_inp, &d->new_readline);
		(d->new_readline) = NULL;
		d->count_quote = ft_count_char(d->new_inp, d->quote);
		if( d->count_quote % 2 != 0)
			break;
	}
	return(d->new_inp);
}

void	check_quote(t_data **data)
{	
	t_data *d;
	
	d = *data;
	while(d->input[d->i] != d->quote)
	{
		if (ft_char_is_dolar(d->input[d->i]))
			ft_is_var(data);
		if(d->input[d->i])
			d->buff[d->buf_idx++] = d->input[d->i++];
		if(!d->input[d->i] && d->count_quote != 0)
		{
			d->new_inp = read_aditional(data);
			d->input = ft_strcat(&d->input, &d->new_inp);
			free(d->new_inp);
			d->new_inp = NULL;
		}
		ft_isquote(data);
		if(d->count_quote == 0 && (d->input[d->i] == '<' || d->input[d->i] == '>' || d->input[d->i] == ' ' || !d->input[d->i]))
			break;
	}	
}

void split_input(t_minishell *ms, t_data **data)
{	
	t_data *d;
	
	d = *data;
	d->i =0;
	while(d->input[d->i] || d->buf_idx > 0)
	{
		if(ft_isaspace(data) || ft_is_rdir(data))
		{
			d->buf_idx = 0;
			d->quote = 0;
		}
		else if (ft_isquote(data))
			check_quote(data);
		else if (ft_char_is_dolar(d->input[d->i]))
			ft_is_var(data);
		else
			d->buff[d->buf_idx++] = d->input[d->i++];
	}
}
