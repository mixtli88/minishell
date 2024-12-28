/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2024/12/27 22:46:00 by mabril           ###   ########.fr       */
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
	ARG,  
 	PIPE ,
	REDIR_IN,
	REDIR_OUT,
	SEPARATOR,
 	BACKGROUND,
 	WORLD,
 	VARIABLE,
 	TOKEN_INVALID,
}	t_type;

/* ***************************   TOKENIZING   ***************************** */
// tokenizing.c
 
 typedef struct s_token
 {
	t_type type; 			//  token type
	char *value; 		// token value.
	int quote_single;
	int quote_double;
	struct s_token *next;
 }		t_token;

typedef struct s_data
{
	t_token *tok_list;
	char 	*input;
	int i;
	int buf_idx;
	char quote;
	char buff[1024];
	char *add_input;
	
}	t_data;


// void	tokenizing(void);
void	tokenizing(t_token **list_token, int ac, char **av);
int		error_syntax(char *str);
void	free_list(t_token *head);
void	error_free(t_token **head, char **av, bool flag_split);
void	creat_token(t_token **head, char *value, int q_s, int q_d);
void	free_table(char **str);
void 	init(t_token **list_token, char **av, bool flag);
t_type get_type(char *token);
void *read_aditional(char quote);
#endif //TOKENIZING_H