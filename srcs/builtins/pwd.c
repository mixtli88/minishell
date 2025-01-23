/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:58:31 by fwu               #+#    #+#             */
/*   Updated: 2025/01/22 19:22:35 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_pwd(char **argv, char **envp)
{
	(void) argv;
	char *env_pwd;

	env_pwd = ft_getenv("PWD", envp);
	if (!env_pwd)
	{
		ft_putendl_fd(ERR_PWD, STDERR_FILENO);
		return (false);
	}
	ft_putendl_fd(env_pwd, STDOUT_FILENO);
	return (true);
}
