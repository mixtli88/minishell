/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:58:31 by fwu               #+#    #+#             */
/*   Updated: 2025/02/07 13:12:32 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_pwd(t_minishell *ms, char **envp)
{
	
	char *env_pwd;

	env_pwd = ft_getenv("PWD", envp);
	if (!env_pwd)
	{
		ft_putendl_fd(ERR_PWD, STDERR_FILENO);
		ms->status = 1;
		return (false);
	}
	ft_putendl_fd(env_pwd, STDOUT_FILENO);
	ms->status = 0;
	free(env_pwd);
	return (true);
}
