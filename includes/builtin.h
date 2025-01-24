/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/01/24 00:00:25 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "tokenizing.h"
# include "exec.h"


# define	EQUAL 		"="
# define	PLAS_EQUAL	"+="

# define	ENV			"env"
# define	PWD			"pwd"
# define	EXIT		"exit"
# define	ECHO		"echo"
# define	EXPORT		"export"
# define	CD			"cd"

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
char	*ft_getenv(char *str, char **envp);
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

char	*ft_strtolower(char *str);

void	error_cd(char *str);

#endif //BUILTIN_H