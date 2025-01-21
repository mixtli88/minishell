/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:00:16 by mabril            #+#    #+#             */
/*   Updated: 2025/01/20 23:47:49 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_char_is_dolar(char i)
{
	char c;

	c = '$';
	if(i == c)
		return(1);
	return(0);
}
// int ft_char_is_rdir(char i)
// {
// 	if(i == '>' || i == '<')
// 		return(1);
// 	return(0);
// }

int ft_count_char(char *str, char c)
{
	int count;

	count = 0;
	if(!str)
		return(count);
	while (*str != '\0')
	{
        if (*str == c) 
            count++;
        str++;     
    }
    return count;
}

int ft_isaspace(t_minishell *ms )
{
	int found;
	t_data *d;
	
	d = &ms->data;
	found = 0;	
	while(d->input[d->i] == ' ' || !d->input[d->i])
	{
		found = 1;
		if (d->buf_idx > 0)
		{
			d->buff[d->buf_idx]='\0';
			creat_token(ms);
			d->buf_idx = 0;
		}
		if(!d->input[d->i])
			break;
		d->i++;
	}
	return(found);
}

int ft_is_pipe_o_logic(t_minishell *ms)
{
	t_data *d;
	int found;
	char *tem;
	int j;

	j = -1;
	d = &ms->data;
	found = 0;	
	while(d->input[d->i] == '|')
	{
		found = 1;
		if(d->buf_idx == 0)
		{
			d->buff[d->buf_idx++] = d->input[d->i++];
			if (d->input[d->i] == d->input[d->i - 1])
				d->buff[d->buf_idx++] = d->input[d->i++];
		}
		tem = d->input + d->i;	
		while(tem[++j] == ' ' || !tem[++j] )
		{
			if (tem[j] == '\0')
			{
				d->flag = 1;
				d->new_inp = read_aditional(ms);
				d->input = ft_strcat(&d->input, &d->new_inp);
				free(d->new_inp);
				d->new_inp = NULL;
				
			}
			if (!tem[j])
				break;
		}
		d->buff[d->buf_idx]='\0';
		creat_token(ms);
		break;		
	}
	return(found);
}
int ft_isquote(t_minishell *ms)
{
	t_data *d;
	
	d = &ms->data;
	if(d->count_quote != 0 && d->input[d->i] != d->quote)
		return(0);
	while(d->input[d->i] == '"' || d->input[d->i] == '\'')
	{
		if(d->count_quote == 0)
		{
			d->quote = d->input[d->i];
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

void ft_is_var(t_minishell *ms)
{
	int j;
	t_data *d;
	
	d = &ms->data;

	j = 0;
	
	
	if(d->count_quote != 0 && d->quote == '\'')
		d->buff[d->buf_idx++] = d->input[d->i++];
	else if ( ft_isalnum(d->input[d->i + 1]) || d->input[d->i + 1] == '_')
	{
		d->i++;
		while (ft_isalnum(d->input[d->i]) || d->input[d->i] == '_')
			d->var_buf[j++] = d->input[d->i++];
		d->var_buf[j] = '\0';
		d->var = getenv(d->var_buf);
		d->var_buf[0] = '\0';
		if (!d->var)
			return;
		j = 0;
		while(d->var[j])
			d->buff[d->buf_idx++] = d->var[j++];
	}
	else if(d->count_quote == 0)
		d->i++;
}

int ft_is_rdir(t_minishell *ms)
{
	int found;
	t_data *d;
	
	d = &ms->data;
	found = 0;
	if(d->input[d->i] == '>' || d->input[d->i] == '<')
	{
		found = 1;
		if(d->buf_idx == 0)
		{
			d->buff[d->buf_idx++] = d->input[d->i++];
			if (d->input[d->i] == d->input[d->i - 1])
				d->buff[d->buf_idx++] = d->input[d->i++];	
			if (d->input[d->i] == d->input[d->i - 1])
				d->buff[d->buf_idx++] = d->input[d->i++];	
		}
		d->buff[d->buf_idx]='\0';
		creat_token(ms);		
	}
	return(found);
}
