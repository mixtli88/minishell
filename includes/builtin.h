/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/01/20 19:59:11 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "tokenizing.h"

# define	EQUAL 		"="
# define	PLAS_EQUAL	"+="

typedef struct s_var
{
	char	*name;
	char	*value;
	char	*operator;
}	t_var;

/* ******************************   UTILS   ******************************* */
// error.c
void	builtin_error(char *builtin, char *err_arg, char *err_msg);
// envp.c
char	**copy_envp(char **envp, char *env);
void	free_envp(char ***envp);
// var.c
void	free_var(t_var *var);
bool	set_var(char *format, char *operator, t_var *var);
bool	find_var(char *format, t_var *var);

/* *****************************   BUILTINS   ***************************** */
// builtin.c
bool	builtin(t_minishell *ms);
// env.c
bool	ft_env(char **argv, char **envp);
// pwd.c
char	*ft_getenv(char *str, char **envp);
bool	ft_pwd(char **argv, char **envp);
// exit.c
bool	ft_exit(char **argv);
// echo.c
bool	ft_echo(char **argv);
// export.c
void	export_var(t_var new_var, char ***envp);
void	ft_export(char **argv, char ***envp);
// cd.c
bool	ft_cd(char **argv, char ***envp);

#endif //BUILTIN_H