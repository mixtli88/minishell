/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:58:31 by fwu               #+#    #+#             */
/*   Updated: 2024/12/21 23:06:34 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	pwd(void)
{
	char	*env_pwd;

	env_pwd = getenv("PWD");
	if (!env_pwd)
	{
		ft_putendl_fd(PWD_ERROR, STDERR_FILENO);
		return (false);
	}
	ft_putendl_fd(env_pwd, STDOUT_FILENO);
	return (true);
}
