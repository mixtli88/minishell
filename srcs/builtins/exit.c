/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:57:47 by fwu               #+#    #+#             */
/*   Updated: 2025/01/30 12:27:31 by mike             ###   ########.fr       */
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
	if (ms->exe.argv && ms->exe.argv[1])
	{
		status = ft_atoi(ms->exe.argv[1]) % 256;
		if (!ft_isint(ms->exe.argv[1]))
		{
			status = 255;
			ft_putstr_fd("exit: ", STDERR_FILENO);
			ft_putstr_fd(ms->exe.argv[1], STDERR_FILENO);
			ft_putendl_fd(ERR_EXIT_NOT_NUMER, STDERR_FILENO);
		}
		else if (ms->exe.argv[2])
		{
			status = 1;
			ft_putendl_fd(ERR_EXIT_TOO_MANY_ARGS, STDERR_FILENO);
			return (false);
		}
	}
	// free_table(ms->exe.argv);
	// free(ms->exe.path);
	// free(ms->exe.name);
	exit(status);
	return (true);
}
