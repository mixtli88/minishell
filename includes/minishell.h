/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/01/09 20:11:20 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "tokenizing.h"
# include "error.h"

typedef struct s_minishell
{
	char	**envp;
}	t_minishell;

typedef struct s_command
{
	char **argv;
	char *cmd_path;
	char **evr;
	int input_fd;
	int output_fd;
	struct s_comand *next;
	
}	t_command;

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