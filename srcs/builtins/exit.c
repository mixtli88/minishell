/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:57:47 by fwu               #+#    #+#             */
/*   Updated: 2025/03/24 11:33:54 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// use echo $? to verify status after exit
// exit a b c => exit: a: numeric argument required
// exit 1 b c => exit: too many arguments
// exit       => echo $? = 0
// exit 257   => echo $? = 1
bool	ft_exit(t_minishell *ms)
{
	int		status;

	status = 0;
	if (ms->exe.arcg > 2)
	{
		ms->status = 1;
		ft_putendl_fd(ERR_EXIT_TOO_MANY_ARGS, STDERR_FILENO);
		return (false);
	}
	if (ms->exe.argv && ms->exe.argv[1])
	{
		status = ft_atoi(ms->exe.argv[1]) % 256;
		if (!ft_isint(ms->exe.argv[1]))
		{
			status = 2;
			ft_putstr_fd("exit: ", STDERR_FILENO);
			ft_putstr_fd(ms->exe.argv[1], STDERR_FILENO);
			ft_putendl_fd(ERR_EXIT_NOT_NUMER, STDERR_FILENO);
		}
	}
	exit(status);
	return (true);
}
