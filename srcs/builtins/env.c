/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:24:23 by fwu               #+#    #+#             */
/*   Updated: 2025/02/07 13:10:26 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_env(t_minishell *ms,  char **envp)
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
		ms->status = 1;
		return (false);
	}
	ms->status = 0;
	return (true);
}
