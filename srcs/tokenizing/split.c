/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:33:19 by mabril            #+#    #+#             */
/*   Updated: 2025/01/04 19:44:15 by mabril           ###   ########.fr       */
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

void ft_isquote(t_data **data)
{
	
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
		(*data)->tem = ft_strcat(&(*data)->tem, &(*data)->new_line);
		// free((*data)->new_line);
		((*data)->new_line) = NULL;
		(*data)->count_quote = ft_count_char((*data)->tem, (*data)->quote);
		if( (*data)->count_quote % 2 != 0)
			break;
	}
	return((*data)->tem);
}

void	check_quote(t_data **data)
{	
	while((*data)->input[(*data)->i] != (*data)->quote)
	{
		if((*data)->input[(*data)->i])
			(*data)->buff[(*data)->buf_idx++] = (*data)->input[(*data)->i++];
		if(!(*data)->input[(*data)->i])
		{
			// printf("Unclouse quote, waiting for sontinuation ");
			(*data)->add_input = read_aditional(data);
			(*data)->input = ft_strcat(&(*data)->input, &(*data)->add_input);
		}
		while((*data)->input[(*data)->i] == (*data)->quote)
		{
			// ft_isquote(data);
			if((*data)->count_quote == 0)
				(*data)->count_quote--;
			else
				(*data)->count_quote--;		
			(*data)->i++;
		}
		if((*data)->count_quote == 0 && ((*data)->input[(*data)->i] == ' ' || !(*data)->input[(*data)->i] || (*data)->input[(*data)->i] == '\''))
			break;
	}	
	(*data)->buff[(*data)->buf_idx]='\0';
	creat_token(data);
}

void split_input(t_data **data)
{	
	while((*data)->input[(*data)->i] || (*data)->buf_idx > 0)
	{
		if ((*data)->input[(*data)->i] == '"' || (*data)->input[(*data)->i] == '\'')
		{
			// esta parte es para hacer la funcion si es quote pero se debe estructurar bien para qeu cuando
			// encuentre un quote seguido si es = 0
			while((*data)->input[(*data)->i] == '"' || (*data)->input[(*data)->i] == '\'')
			{
				if((*data)->count_quote == 0)
				{
					(*data)->quote = (*data)->input[(*data)->i];
					(*data)->count_quote++;
				}
				else
					(*data)->count_quote--;
				(*data)->i++;
			}
			if((*data)->count_quote != 0)
				check_quote(data);
		}
		else if(ft_isaspace((*data)->input[(*data)->i]) || !(*data)->input[(*data)->i])
		{
			if ((*data)->buf_idx > 0)
			{
				(*data)->buff[(*data)->buf_idx]='\0';
				creat_token(data);
			}
			
			(*data)->i++;
		}
		else
			(*data)->buff[(*data)->buf_idx++] = (*data)->input[(*data)->i++];
	}
}
