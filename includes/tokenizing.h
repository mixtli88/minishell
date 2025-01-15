/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/01/14 17:56:20 by mabril           ###   ########.fr       */
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
}	t_type;

typedef enum e_redirection
{

 	NOT,
	SINGLE_IN,
 	SINGLE_OUT,
	DOUBLE_IN,
	DOUBLE_OUT,
 	
}	t_redirection;

/* ***************************   TOKENIZING   ***************************** */
// tokenizing.c
 
 typedef struct s_token
 {
	t_type type; 			//  token type
	char *value; 		// token value.
	int quote;
	struct s_token *next;
 }		t_token;


typedef struct s_cmd
{
	char **argv;
	char *cmd_path;
	char **evr;
	t_redirection redi;
	char *valiu_redir;
	char *limiter;
	
	struct s_cmd *next;
	
}	t_cmd;

typedef struct s_data
{
	t_token *tok_list;
	t_token	*token_cur;
	
	char 	quote;
	char 	*input;

	int 	i;
	char 	buff[1024];
	char 	*add_input;
	
	int buf_idx;
	char *tem;
	char *new_line;
	int count_quote;
	
	char **envp;
	
	t_cmd *cmd_list;
	t_cmd *cur_cmd;
	int arg_c;

	
}	t_data;
// void	tokenizing(void);
void	tokenizing(t_token **list_token, int ac, char **av);
int		error_syntax(char *str);
void	free_table(char **str);
void	free_cmd_list(t_cmd **cmd_list);
void	free_token_list(t_token *token_list);
void	free_data(t_data **data);
void	error_free(t_data **data);

void	creat_token(t_data **data);

t_type 	type_token(char *token);
char 	*read_aditional(t_data **data);
void	check_quote(t_data **data);
void 	split_input(t_data **data);

int 	ft_isaspace(t_data **data);
int 	ft_count_char(char *str, char c);
int 	ft_isquote(t_data **data);

void buil_cmd_list(t_data **data);
t_cmd *creat_cmd(t_data **data);

void tok_is_cmd(t_data **data);
void tok_is_redi(t_data **data);
void tok_is_pipe(t_data **data);

void init_data(t_data **data);
void init_new_token(t_data **data, t_token **new);
void init_new_cmd(t_cmd **cmd);

#endif //TOKENIZING_H