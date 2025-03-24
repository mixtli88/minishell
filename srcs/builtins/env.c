/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:24:23 by fwu               #+#    #+#             */
/*   Updated: 2025/03/24 12:59:15 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_env(t_minishell *ms,  char **envp)
{
	int j;
	int	i;

	i = -1;
	j = 1;
	while(ms->exe.argv[j] && ft_strcmp(ms->exe.argv[j], "env") == 0)
		j++;
	if(ms->exe.argv[j] && ft_strcmp(ms->exe.argv[j], "env") == 1)
	{
		ft_putstr_fd(ERR_ENV_NEXTARG, STDOUT_FILENO);
		ft_putstr_fd(ms->exe.argv[1], STDOUT_FILENO);
		ft_putendl_fd(ERR_DIRECTORY, STDOUT_FILENO);
		ms->status = 1;
		return (false);
	}
	while (envp && envp[++i])
		ft_putendl_fd(envp[i], ms->exe.outfd);
	if (i == 0)
	{
		ft_putendl_fd(ERR_ENV, STDERR_FILENO);
		ms->status = 1;
		return (false);
	}
	ms->status = 0;
	return (true);
}
