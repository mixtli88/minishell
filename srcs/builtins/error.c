/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:29:45 by fwu               #+#    #+#             */
/*   Updated: 2025/03/24 11:34:26 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtin_error(t_minishell *ms, char *err_arg)
{
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(err_arg, STDERR_FILENO);
	ft_putstr_fd(ERR_NOT_VAILD_IDENTIFIER, STDERR_FILENO);
	ms->status = 1;
}

void	error_cd(t_minishell *ms, char *str, int err)
{
	if (err == ENOENT) 
	{
		ft_putstr_fd("mini: ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putendl_fd("cd : No such file or directory", STDERR_FILENO);
	}
	else if (err == ENOTDIR) 
	{
		ft_putstr_fd("minil: ", STDERR_FILENO);
		ft_putstr_fd(str, STDERR_FILENO);
		ft_putendl_fd(" cd : Not a directory", STDERR_FILENO);
	}
	else if (err == EMARG) 
		ft_putendl_fd(ERR_EXIT_TOO_MANY_ARGS, STDERR_FILENO);
	else
	{
		ft_putstr_fd("cd", STDERR_FILENO);
	}
	ms->status = 1;
}

void	perror_cmd(char *str)
{
	perror(str);
    exit(EXIT_FAILURE);
}

void	error_directory(t_minishell *ms)
{
	ms->status = 126;
	ft_putstr_fd("bash: ", STDERR_FILENO);
	ft_putstr_fd(ms->exe.argv[0], STDERR_FILENO);
	ft_putendl_fd(": Is a directory", STDERR_FILENO);
}

void	error_path_cmd(t_minishell *ms)
{
	ms->status = 127;
	ft_putstr_fd("bash: ", STDERR_FILENO);
	ft_putstr_fd(ms->exe.argv[0], STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
}