/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:24:23 by fwu               #+#    #+#             */
/*   Updated: 2025/01/12 22:41:59 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_env(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		ft_putendl_fd(envp[i], STDOUT_FILENO);
		i++;
	}
	if (i == 0)
	{
		ft_putendl_fd(ERR_ENV, STDERR_FILENO);
		return (false);
	}
	return (true);
}
