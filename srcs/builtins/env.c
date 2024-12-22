/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:24:23 by fwu               #+#    #+#             */
/*   Updated: 2024/12/21 23:06:16 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	env(t_minishell ms)
{
	int	i;

	i = 0;
	while (ms.envp && ms.envp[i])
	{
		ft_putendl_fd(ms.envp[i], STDOUT_FILENO);
		i++;
	}
	if (i == 0)
	{
		ft_putendl_fd(ENV_ERROR, STDERR_FILENO);
		return (false);
	}
	return (true);
}
