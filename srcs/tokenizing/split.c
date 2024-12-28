/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:33:19 by mabril            #+#    #+#             */
/*   Updated: 2024/12/27 22:46:03 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void *read_aditional(char quote)
{
	
}
void *split_input(t_data **data, char *input)
{
	int i;
	int buf_idx;
	int quote_double;
	int quote_simple;
	
	i = 0;
	buf_idx = 0;
	while((*data)->input[i])
	{
		if(ft_isaspace(input[i]))
		{
			if ((*data)->buf_idx > 0)
			{
				(*data)->buff[buf_idx]='\0';
				creat_token(&(*data)->tok_list, (*data)->buff, 0, 0);
				buf_idx = 0;
			}
		}
		else if (input[i] == '"' || input[i] == '\'')
		{
			(*data)->quote = input[i++];
			quote_double = ((*data)->quote == '"');
			quote_simple = ((*data)->quote == '\'');
			if(buf_idx == 0)
				(*data)->buff[buf_idx++] = (*data)->quote;
			while(input[i] && input[i] != (*data)->quote )
				(*data)->buff[buf_idx++] = input[i++];
			if(!input[i])
			{
				printf("Unclouse quote, waiting for sontinuation ");
				(*data)->add_input = read_aditional((*data)->quote);
			}
		}
		
	}
}
