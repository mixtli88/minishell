/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/01/23 23:17:20 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

# include <unistd.h>
# include "../libft/libft.h"
# include "readline/history.h"
# include "readline/readline.h"

typedef enum e_type
{
	N_T,
	CMD,
	PIPE,
	REDIR,
	// LOGIC,
}					t_type;

typedef enum e_redirection
{
	NOT,
	SINGLE_IN,
	SINGLE_OUT,
	DOUBLE_IN,
	DOUBLE_OUT,
}					t_redirection;
typedef enum e_logic
{
	NO,
	OR,
	AND,
}			t_logic;

/* ***************************   TOKENIZING   ***************************** */

// tokenizing.c

typedef struct s_token
{
	t_type			type;
	char			*value;
	struct s_token	*next;
}					t_token;

typedef struct s_cmd
{
	int				id;
	char			**argv;
	char			*path;
	t_redirection	rdir;
	char			*fd_rdir;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_exe
{
	int		infd;
	int		outfd;
	char	*name;	
	char	*path;
	char	**argv;
	char	***envp;	
}		t_exe;

typedef struct s_data
{
	char			*input;
	int				i;
	int				count_quote;

	char			buff[1024];
	int				buf_idx;

	char			*new_readline;
	char			*new_inp;

	t_token			*tok_list;
	t_token			*token_cur;
	t_token			*tok_tem;
	char			quote;

	char			var_buf[1024];
	char			*var;

	char			***envp;
	int				arg_c;
	t_cmd			*cmd_list;
	t_cmd			*cur_cmd;

	char			*full_path;
	int				flag;
	int				count;
}					t_data;

typedef struct s_minishell
{
	t_data			data;
	t_exe			exe;
	char			***envp;
}					t_minishell;

// void	tokenizing(void);
void				lexer(t_minishell *ms);
int					error_sy(char *str);
void				free_table(char **str);
void				free_cmd_list(t_cmd **cmd_list);
void				free_token_list(t_token *token_list);

void				free_data(t_minishell *ms);
void				error_syntax(t_minishell *ms);
void				error_quote(t_minishell *ms);

void				creat_token(t_minishell *ms);

t_type				type_token(char *token);
char				*read_aditional(t_minishell *ms);
void				check_quote(t_minishell *ms);
void				split_input(t_minishell *ms);

int					ft_isaspace_inp(t_minishell *ms);
int					ft_count_char(char *str, char c);
int					ft_isquote(t_minishell *ms);

void				buil_cmd_list(t_minishell *ms);
t_cmd				*creat_nod(t_minishell *ms);

void				tok_is_cmd(t_minishell *ms);
void				tok_is_redi(t_minishell *ms);
void				tok_is_pipe(t_minishell *ms);

void				init_data(t_minishell *ms);
void				init_new_token(t_token **new);
void				init_new_cmd(t_cmd **cmd);
int					find_path(t_minishell *ms);

int					ft_char_is_dolar(char i);
void				ft_is_var(t_minishell *ms);
int					ft_is_rdir(t_minishell *ms);

void				print_cmd(t_minishell *ms);
int					not_path(t_minishell *ms);
void				error_directory(t_minishell *ms);
int					ft_is_pipe(t_minishell *ms);
void				handle_pipe_input(t_minishell *ms);

void				error_path_cmd(t_cmd *cmd);

void				create_cmd(t_minishell *ms);
void				char_is_rdir(t_minishell *ms);

#endif // TOKENIZING_H