/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:58:31 by fwu               #+#    #+#             */
/*   Updated: 2024/12/22 22:09:08 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_pwd(void)
{
	char	*env_pwd;

	env_pwd = getenv("PWD");
	if (!env_pwd)
	{
		ft_putendl_fd(ERR_PWD, STDERR_FILENO);
		return (false);
	}
	ft_putendl_fd(env_pwd, STDOUT_FILENO);
	return (true);
}
