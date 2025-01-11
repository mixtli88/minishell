/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/01/10 21:46:21 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "tokenizing.h"
# include "error.h"
typedef enum e_redirection
{

 	SINGLE_IN,
 	SINGLE_OUT,
	DOUBLE_IN,
	DOUBLE_OUT,
 	
}	t_redirection;

typedef struct s_minishell
{
	char	**envp;
}	t_minishell;

typedef struct s_cmd
{
	char **argv;
	char *cmd_path;
	char **evr;
	t_redirection redi;
	char *valiu_redir; "t.txt"
	char *limiter;
	
	struct s_cmd *next;
	
}	t_cmd;

/* ****************************   BUILTINS   ****************************** */
// builtin.c
bool	builtin(t_minishell *ms);
// env.c
bool	ft_env(char *const envp[]);
// pwd.c
bool	ft_pwd(void);
// exit.c
bool	ft_exit(char *const argv[]);
// echo.c
bool	ft_echo(char *const argv[]);

/* ******************************   EXEC   ******************************** */
// exex.c
void	exec(void);
void ft_minishell_loop(void);
// void ft_minishell_loop(int input_fd);
#endif //MINISHELL_H