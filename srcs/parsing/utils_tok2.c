/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tok2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:00:58 by mabril            #+#    #+#             */
/*   Updated: 2025/02/18 12:44:29 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_pipe_input(t_minishell *ms)
{
	t_data	*d;
	char	*tem;
	int		j;

	j = -1;
	d = &ms->data;
	tem = d->input + d->i;
	while (ft_isspace(tem[++j]) || !tem[j])
	{
		if (tem[j] == '\0')
		{
			d->flag = 1;
			g_signal_status = 1;
			d->new_inp = readline(">");
			if (g_signal_status == 2 || !d->new_inp)
			{
				if (!d->new_inp)
					error_pipe(ms);
				d->flag = -1;
				return;
			}
			d->input = ft_strcat(&d->input, &d->new_inp);
			free(d->new_inp);
			d->new_inp = NULL;
			tem = d->input + d->i;
			j = -1;
		}
	}
}

void	 ft_is_var(t_minishell *ms)
{
	int		j;
	t_data	*d;

	d = &ms->data;
	j = 0;
	if ((d->count_quote != 0 && d->quote == '\'') || (d->input[d->i + 1] == ' '
			|| !d->input[d->i + 1]))
		d->buff[d->buf_idx++] = d->input[d->i++];
	else if(d->input[d->i + 1] == '?' || d->input[d->i + 1] == '$')
		handle_question_mark(ms);
	else if (ft_isalnum(d->input[d->i + 1]) || d->input[d->i + 1] == '_')
	{
		d->i++;
		while (ft_isalnum(d->input[d->i]) || d->input[d->i] == '_')
			d->var_buf[j++] = d->input[d->i++];
		d->var_buf[j] = '\0';
		d->var = ft_getenv(d->var_buf, *(ms->envp));
		d->var_buf[0] = '\0';
		if (!d->var)
			return ;
		j = 0;
		while (d->var[j])
			d->buff[d->buf_idx++] = d->var[j++];
	}
	else if (d->count_quote == 0)
		d->i++;
}

int	ft_is_rdir(t_minishell *ms)
{
	int		found;
	t_data	*d;
 
	d = &ms->data;
	found = 0;
	if (d->input[d->i] == '>' || d->input[d->i] == '<')
	{
		found = 1;
		if (d->buf_idx == 0)
		{
			d->buff[d->buf_idx++] = d->input[d->i++];
			if (d->input[d->i] == d->input[d->i - 1])
				d->buff[d->buf_idx++] = d->input[d->i++];
		}
		d->buff[d->buf_idx] = '\0';
		creat_token(ms);
	}
	return (found);
}

void if_is_just_quote(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (!d->tok_list && d->count_quote == 0 && 
		d->input[d->i - 1] == d->input[d->i] && 
		(d->input[d->i + 1] == ' ' || d->input[d->i + 1] == '\0'))
		{
			d->buff[d->buf_idx++] = d->quote;
			d->buff[d->buf_idx++] = d->quote;
		}
}
void handle_question_mark(t_minishell *ms)
{
	t_data	*d;
	int 	j;
	
	j = 0;
	d = &ms->data;
	if(d->input[d->i + 1] == '?')
	{
		d->var = ft_itoa(ms->status);
		while (d->var[j])
				d->buff[d->buf_idx++] = d->var[j++];
	}
	else
	{
		d->var = ft_itoa(getpid());
		while (d->var[j])
				d->buff[d->buf_idx++] = d->var[j++];
	}
	free(d->var);
	d->var = NULL;
	d->i += 2;
}


	

// int ft_is_pipe_o_logic(t_minishell *ms)
// {
// 	t_data *d;
// 	int found;
// 	char *tem;
// 	int j;

// 	j = -1;
// 	d = &ms->data;
// 	found = 0;
// 	while(d->input[d->i] == '|')
// 	{
// 		found = 1;
// 		if(d->buf_idx == 0)
// 		{
// 			d->buff[d->buf_idx++] = d->input[d->i++];
// 			if (d->input[d->i] == d->input[d->i - 1])
// 				d->buff[d->buf_idx++] = d->input[d->i++];
// 		}
// 		tem = d->input + d->i;
// 		while(tem[++j] == ' ' || !tem[j] )
// 		{
// 			if (tem[j] == '\0')
// 			{
// 				d->flag = 1;
// 				d->new_inp = read_aditional(ms);
// 				d->input = ft_strcat(&d->input, &d->new_inp);
// 				free(d->new_inp);
// 				d->new_inp = NULL;
// 				tem = d->input + d->i;
// 			}
// 			j = 0;
// 			if (!tem[j])
// 				break ;
// 		}
// 		d->buff[d->buf_idx]='\0';
// 		creat_token(ms);
// 		break ;
// 	}
// 	return(found);
// }
