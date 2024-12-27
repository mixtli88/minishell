/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2024/12/26 17:30:22 by mabril           ###   ########.fr       */
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
	struct s_token *next;
 }		t_token;

typedef struct s_data
{
	t_token *tok_list;
	char 	*input;
}	t_data;


// void	tokenizing(void);
void	tokenizing(t_token **list_token, int ac, char **av);
int		error_syntax(char *str);
void	free_list(t_token *head);
void	error_free(t_token **head, char **av, bool flag_split);
void	creat_token(t_token **head,char *value, t_type type);
void	free_table(char **str);
void 	init(t_token **list_token, char **av, bool flag);

#endif //TOKENIZING_H