/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/01/19 13:50:20 by fwu              ###   ########.fr       */
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

/* ****************************   BUILTINS   ****************************** */
// envp.c
char	**copy_envp(char **envp, char *env);
void	free_envp(char ***envp);
// builtin.c
bool	builtin(t_minishell *ms);
// env.c
bool	ft_env(char **envp);
// pwd.c
bool	ft_pwd(void);
// exit.c
bool	ft_exit(char *argv[]);
// echo.c
bool	ft_echo(char *argv[]);
// cd.c
bool	ft_cd(char *argv[], char *envp[]);
// export.c
void	ft_export(char **argv, char ***envp);
// var.c
void	free_var(t_var *var);
bool	set_var(char *format, char *operator, t_var *var);
bool	find_var(char *format, t_var *var);
// error.c
void	builtin_error(char *builtin, char *err_arg, char *err_msg);

#endif //BUILTIN_H