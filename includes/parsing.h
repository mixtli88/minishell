/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/03/24 13:10:36 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include "../libft/libft.h"
# include "readline/history.h"
# include "readline/readline.h"

typedef enum e_typecmd
{
	N_T,
	CMD,
	PIPE,
	REDIR,
	// LOGIC,
}					t_typecmd;

typedef enum e_typerdir
{
	NOT,
	SINGLE_IN,
	SINGLE_OUT,
	DOUBLE_IN,
	DOUBLE_OUT,
}					t_typerdir;

/* ***************************   TOKENIZING   ***************************** */

// tokenizing.c

typedef struct s_token
{
	t_typecmd		type;
	char			*value;
	struct s_token	*next;
}					t_token;

typedef struct s_rdir
{
	t_typerdir		type;
	char			*fd_rdir;
	struct s_rdir	*next;
}					t_rdir;

typedef struct s_cmd
{
	int				id;
	char			**argv;
	char			*path;
	t_rdir			*rdir;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_exe
{
	int 			id;
	int				arcg;
	int				infd;
	int				outfd;
	char			*name;	
	char			*path;
	char			**argv;
	char			***envp;	
}		t_exe;

typedef struct s_fd
{
	int				cmd_num;
	int				pipe_num;
	int				**pipe;
	int				infile;
	int				outfile;
}	t_fd;

typedef struct s_data
{
	char			*input;
	char			*new_inp;
	int				i;
	int				flag;
	
	char			buff[1024];
	int				buf_idx;
	
	int				count_quote;
	char			quote;
	int 			in_quotes;
	
	char			*new_readline;
	
	t_token			*token_list;
	t_token			*token_cur;
	t_token			*token_tem;
	t_token			*token_last;

	int				arg_c;
	int				count_cmd;
	t_cmd			*cmd_list;
	t_cmd			*cur_cmd;
	
	char			var_buf[1024];
	char			*var;

	char			***envp;
	char			*full_path;

	char			*path;
	char 			*last_slash;
	
	int 			g_stdin;
	
	char 			*heredoc;	
}					t_data;

typedef struct s_uid
{
	char			*user;
	char			buffer[1024];
	char 			line[1024];
	char 			*name;
	char		 	*line_start;
	char 			*line_end;
	ssize_t 		bytes_read;
} 					t_uid;

typedef struct s_var
{
	char			*name;
	char			*value;
	char			*operator;
}					t_var;

typedef struct s_minishell
{
	t_data			data;
	t_exe			exe;
	t_fd			fd;
	t_var			oldpwd_var;
	t_var			pwd_var;
	t_uid			uid;
	char 			*uid_str;
	int 			status;
	char			***envp;
	int				err;
}					t_minishell;

char		*ft_strdup(const char *s1);

void		free_table(char **str);
void		free_cmd_list(t_cmd **cmd_list);
void		free_token_list(t_token *token_list);
void		free_data(t_minishell *ms);
void		free_rdir_list(t_rdir *rdir_list);

bool		error_syntax(t_minishell *ms);
void		error_quote(void);
void		error_pipe(t_minishell *ms);

void		creat_token(t_minishell *ms);
t_typecmd	type_token(char *token);

void 		if_is_just_quote(t_minishell *ms);
int			ft_isquote(t_minishell *ms);
int			ft_isaspace_inp(t_minishell *ms);
bool		split_input(t_minishell *ms);

int			ft_count_char(char *str, char c);

void		buil_cmd_list(t_minishell *ms);
t_cmd		*creat_nod(t_minishell *ms);

void		tok_is_cmd(t_minishell *ms);
void		tok_is_redi(t_minishell *ms);
void		tok_is_pipe(t_minishell *ms);

void		create_cmd(t_minishell *ms);
void		init_data(t_minishell *ms);

void		init_new_token(t_token **new);
void		init_new_cmd(t_cmd **cmd);

int			ft_char_is_dolar(char i);
void		ft_is_var(t_minishell *ms);
void		if_var_alpnum(t_minishell *ms);
void		handle_var_in_herdoc(t_minishell *ms);

void 		creat_nod_rdir(t_minishell *ms);
int			ft_is_rdir(t_minishell *ms);
void 		creat_nod_rdir(t_minishell *ms);
void		type_rdir(t_minishell *ms, t_rdir **new);

int			ft_is_pipe(t_minishell *ms);
void		handle_pipe_input(t_minishell *ms);

void 		handle_question_mark(t_minishell *ms);
void		print_cmd(t_minishell *ms);

void 		set_sig_local(t_minishell *ms);
bool 		on_signal(t_minishell *ms); 

void 		ft_heredoc(t_minishell *ms, t_rdir *new);
bool 		its_heredoc(t_minishell *ms);

void		get_user_uid(t_minishell *ms);
void 		get_uid(t_minishell *ms, int fd);
#endif