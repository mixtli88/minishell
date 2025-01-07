/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:00:16 by mabril            #+#    #+#             */
/*   Updated: 2025/01/06 20:26:44 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_count_char(char *str, char c)
{
	int count;

	count = 0;
	while (*str != '\0')
	{
        if (*str == c) 
            count++;
        str++;     
    }
    return count;
}

int ft_isaspace(t_data **data )
{
	int found;
	t_data *d;
	
	d = *data;
	found = 0;	
	while(d->input[d->i] == ' ' || !d->input[d->i])
	{
		found = 1;
		if (d->buf_idx > 0)
		{
			d->buff[d->buf_idx]='\0';
			creat_token(data);
			d->buf_idx = 0;
		}
		if(d->input[d->i])
			d->i++;
		else
			break;
	}
	return(found);
}

int ft_isquote(t_data **data)
{
	t_data *d;
	
	d = *data;
	if(d->count_quote != 0 && d->input[d->i] != d->quote)
		return(0);
	while(d->input[d->i] == '"' || d->input[d->i] == '\'')
	{
		if(d->count_quote == 0)
		{
			d->quote = d->input[(d)->i];
			d->count_quote++;
		}
		else if(d->input[d->i] == d->quote )
			d->count_quote--;
		if(d->count_quote == 1 && d->input[d->i + 1] != d->quote)
		{
			d->i++;
			break;
		}
		d->i++;
	}
	return(d->count_quote);
}
