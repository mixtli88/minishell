/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:33:19 by mabril            #+#    #+#             */
/*   Updated: 2025/01/06 20:26:54 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *read_aditional(t_data **data)
{
	t_data *d;
	
	d = *data;
	while(1)
	{
		d->new_line = readline(">");
		if(!d->new_line)
		{
			printf("Error, for closing quote\n");
			if(d->tem)
			{
				free(d->tem);
				d->tem = NULL;
			}
			return(NULL);
		}
		d->tem = ft_strcat(&d->tem, &d->new_line);
		(d->new_line) = NULL;
		d->count_quote = ft_count_char(d->tem, d->quote);
		if( d->count_quote % 2 != 0)
			break;
	}
	return(d->tem);
}

void	check_quote(t_data **data)
{	
	t_data *d;
	
	d = *data;
	while(d->input[d->i] != d->quote)
	{
		if(d->input[d->i])
			d->buff[d->buf_idx++] = d->input[d->i++];
		if(!d->input[d->i] && d->count_quote != 0)
		{
			d->add_input = read_aditional(data);
			d->input = ft_strcat(&d->input, &d->add_input);
		}
		ft_isquote(data);
		if(d->count_quote == 0 && (d->input[d->i] == ' ' || !d->input[d->i]))
			break;
	}	
}

void split_input(t_data **data)
{	
	t_data *d;
	
	d = *data;
	while(d->input[d->i] || d->buf_idx > 0)
	{
		if(ft_isaspace(data))
		{
			d->buf_idx = 0;
			d->quote = 0;
		}
		else if (ft_isquote(data))
				check_quote(data);
		else
			d->buff[d->buf_idx++] = d->input[d->i++];
	}
}
