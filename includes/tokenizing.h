/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/01/06 21:46:50 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

#include "../libft/libft.h"
# include "readline/readline.h"
# include "readline/history.h"

typedef enum e_type
{
	CMD,  
 	PIPE ,
	REDIR,
 	VARIABLE,
	TOKEN_INVALID,
}	t_type;

/* ***************************   TOKENIZING   ***************************** */
// tokenizing.c
 
 typedef struct s_token
 {
	t_type type; 			//  token type
	char *value; 		// token value.
	int quote;
	struct s_token *next;
 }		t_token;

typedef struct s_data
{
	t_token *tok_list;
	char 	*input;
	int 	i;

	char 	quote;
	char 	buff[1024];
	char 	*add_input;
	
	int buf_idx;
	char *tem;
	char *new_line;
	int count_quote;
}	t_data;


// void	tokenizing(void);
void	tokenizing(t_token **list_token, int ac, char **av);
int		error_syntax(char *str);
void	free_list(t_token *head);
void	error_free(t_token **head, char **av, bool flag_split);
void	creat_token(t_data **data);
void	free_table(char **str);

t_type 	type_token(char *token);
char 	*read_aditional(t_data **data);
void	check_quote(t_data **data);
void 	split_input(t_data **data);
void 	ft_init_data(t_data **data);
int ft_isaspace(t_data **data);
int ft_count_char(char *str, char c);
int ft_isquote(t_data **data);
#endif //TOKENIZING_H