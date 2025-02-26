/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/02/25 19:26:08 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "parsing.h"

# define EXIT	"exit"
# define EXPORT	"export"

/* **************************   ERROR MESSAGE   *************************** */
# define ERR_ENV "ENV ERROR"
# define ERR_PWD "PWD ERROR"
# define ERR_EXIT_NOT_NUMER ": numeric argument required"
# define ERR_EXIT_TOO_MANY_ARGS "exit: too many arguments"
# define ERR_NOT_VAILD_IDENTIFIER "not a valid identifier"

# define	EQUAL 		"="
# define	PLAS_EQUAL	"+="

# define	ENV			"env"
# define	PWD			"pwd"
# define	EXIT		"exit"
# define	ECHO		"echo"
# define	EXPORT		"export"
# define	CD			"cd"
# define	UNSET		"unset"

# define WRITE_PIPE_IDX 1
# define READ_PIPE_IDX 0

/* ******************************   UTILS   ******************************* */
// error.c
void	builtin_error(char *builtin, char *err_arg, char *err_msg);
void	error_cd(char *str, int err);
void	perror_cmd(char *str);
void	error_directory(t_minishell *ms);
void	error_path_cmd(t_minishell *ms);
// envp.c
char	**copy_envp(char **envp, char *env);
void	free_envp(char ***envp);
char	*ft_getenv(char *str, char **envp);
// var.c
void	free_var(t_var *var);
bool	set_var(char *format, char *operator, t_var *var);
bool	find_var(char *format, t_var *var);

/* *****************************   BUILTINS   ***************************** */
// builtin.c
bool	is_builtin(t_minishell *ms);
bool	builtin(t_minishell *ms, t_cmd *cmd);
// env.c
bool	ft_env(t_minishell *ms, char **envp);
// pwd.c
bool	ft_pwd(t_minishell *ms,  char **envp);
// exit.c
bool	ft_exit(t_minishell *ms);
// echo.c
bool	ft_echo(t_minishell *ms);
// export.c
void	export_var(t_var new_var, char ***envp);
void	ft_export(t_minishell *ms, char **argv, char ***envp);
// cd.c
bool	ft_cd(t_minishell *ms, t_cmd *cmd);
void handle_signal_son(int sig);



/* ******************************   EXEC   ******************************** */
// utils_exe.c
void	prepare_t_exe(t_minishell	*ms, t_cmd *cmd);
// execution.c
void	execution(t_minishell	*ms);
// error_exc.c
void    error_execve(t_minishell *ms);
void    error_open_file(t_minishell *ms,   char *file);
// fd.c
void    rdir_fd(t_minishell *ms, t_cmd *cmd);
void	fd_and_pipe(t_minishell	*ms);
void    get_rdir_for_fd(t_minishell	*ms, t_cmd *cmd);   
void	get_fd_exe(t_minishell	*ms, t_cmd *cmd);
// free_exe_fd.c
void	close_fd(t_minishell    *ms, t_cmd *cmd);
void	close_fd_exe(t_minishell	*ms);
void	free_t_fd(t_minishell    *ms);
void	reset_t_exe(t_minishell *ms);

void    get_cd_path(t_minishell *ms, t_cmd *cmd);
void	reset_t_var(t_minishell *ms);
void	ft_unset(t_minishell *ms, char *var);

int creat_tem_heredoc(char *heredoc);

#endif 