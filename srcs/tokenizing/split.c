/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:33:19 by mabril            #+#    #+#             */
/*   Updated: 2024/12/30 00:22:04 by mabril           ###   ########.fr       */
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

char *read_aditional(t_data **data)
{
	int i;

	i = 0;
	while(1)
	{
		(*data)->new_line = readline(">");
		if(!(*data)->new_line)
		{
			printf("Error, for closing quote\n");
			if((*data)->tem)
			{
				free((*data)->tem);
				(*data)->tem = NULL;
			}
			return(NULL);
		}
		(*data)->tem = ft_strcat((*data)->tem, (*data)->new_line);
		free((*data)->new_line);
		((*data)->new_line) = NULL;
		(*data)->count_quote = ft_count_char((*data)->tem, (*data)->quote);
		if( (*data)->count_quote % 2 != 0)
			break;
	}
	return((*data)->tem);
}

void	check_quote(t_data **data)
{	
	while((*data)->input[(*data)->i] && (*data)->input[(*data)->i] != (*data)->quote)
	{
		(*data)->buff[(*data)->buf_idx++] = (*data)->input[(*data)->i++];
		if(!(*data)->input[(*data)->i])
		{
			printf("Unclouse quote, waiting for sontinuation ");
			(*data)->add_input = read_aditional(data);
			(*data)->input = ft_strcat(&(*data)->input, (*data)->add_input);
		}
		if((*data)->input[(*data)->i] == (*data)->quote)
		{
			(*data)->count_quote--;		
			(*data)->i++;		
			if((*data)->count_quote == 0 && (*data)->input[(*data)->i] == ' ')
					break;
			else if((*data)->count_quote == 0 && (*data)->input[(*data)->i++] == (*data)->quote)
			{
				(*data)->count_quote++;	
				(*data)->i++;	
			}
		}
	}	
}

void split_input(t_data **data)
{	
	while((*data)->input[(*data)->i])
	{
		if(ft_isaspace((*data)->input[(*data)->i]))
		{
			if ((*data)->buf_idx > 0)
			{
				(*data)->buff[(*data)->buf_idx]='\0';
				creat_token(data);
				(*data)->buf_idx = 0;
				(*data)->quote = 0;
			}
			(*data)->i++;
		}
		else if ((*data)->input[(*data)->i] == '"' || (*data)->input[(*data)->i] == '\'')
		{
			(*data)->quote = (*data)->input[(*data)->i];
			while((*data)->input[(*data)->i++] == (*data)->quote )
				(*data)->count_quote++;
			check_quote(data);
		}else
			(*data)->buff[(*data)->buf_idx++] = (*data)->input[(*data)->i++];
		(*data)->i++;
	}
}
