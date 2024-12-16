/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2024/12/16 12:24:52 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

#include "../libft/libft.h"
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
	struct t_token *next;
 }		t_token;

void	tokenizing(void);

#endif //TOKENIZING_H