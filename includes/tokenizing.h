/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2024/12/20 21:35:21 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

#include "../libft/libft.h"
# include "readline/readline.h"
# include "readline/history.h"
#define TOKEN_COMMAND     1
#define TOKEN_ARGUMENT    2
#define TOKEN_PIPE        3
#define TOKEN_REDIRECTION 4
#define TOKEN_SEPARATOR   5
#define TOKEN_BACKGROUND  6
#define TOKEN_STRING      7
#define TOKEN_VARIABLE    8
#define TOKEN_INVALID     9
/* ***************************   TOKENIZING   ***************************** */
// tokenizing.c
 
 typedef struct s_token
 {
	int type; 			//  token type
	char *value; 		// token value.
	struct s_token *next;
 }		t_token;

// void	tokenizing(void);
void	tokenizing(t_token **list_token, int ac, char **av);
int		error_syntax(char *str);
void	free_list(t_token *head);
void	error_free(t_token **head, char **av, bool flag_split);
void creat_token(t_token **head,char *value, int type);
void	free_table(char **str);
void 	init(t_token **list_token, char **av, bool flag);

#endif //TOKENIZING_H