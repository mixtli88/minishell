/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 17:57:47 by fwu               #+#    #+#             */
/*   Updated: 2025/01/23 23:48:10 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// use echo $? to verify status after exit
// exit a b c => exit: a: numeric argument required
// exit 1 b c => exit: too many arguments
// exit       => echo $? = 0
// exit 257   => echo $? = 1
bool	ft_exit(char **argv)
{
	int		status;

	status = 0;
	if (argv && argv[1])
	{
		status = ft_atoi(argv[1]) % 256;
		if (!ft_isint(argv[1]))
		{
			status = 255;
			ft_putstr_fd("exit: ", STDERR_FILENO);
			ft_putstr_fd(argv[1], STDERR_FILENO);
			ft_putendl_fd(ERR_EXIT_NOT_NUMER, STDERR_FILENO);
		}
		else if (argv[2])
		{
			status = 1;
			ft_putendl_fd(ERR_EXIT_TOO_MANY_ARGS, STDERR_FILENO);
			return (false);
		}
	}
	// exit(EXIT_SUCCESS);
	exit(status);
	return (true);
}
