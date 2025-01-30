/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:17:40 by fwu               #+#    #+#             */
/*   Updated: 2025/01/28 12:41:06 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// echo          => '\n'
// echo abc      => abc'\n'
// echo a b c    => a b c'\n'
// echo -n       => ''
// echo -n abc   => abc
// echo -n a b c => a b c
bool	ft_echo(t_minishell *ms)
{
	// ft_putendl_fd("echo", STDOUT_FILENO);
	bool	flag_new_line;
	int		i;

	flag_new_line = true;
	i = 1;
	while (ms->exe.argv && ms->exe.argv[i])
	{
		if (i == 1 && ft_strncmp(ms->exe.argv[1], "-n", 2) == 0)
			flag_new_line = false;
		else
		{
			ft_putstr_fd(ms->exe.argv[i], ms->exe.outfd);
			if (ms->exe.argv[i + 1])
				ft_putstr_fd(" ", ms->exe.outfd);
		}
		i++;
	}
	if (flag_new_line)
		ft_putstr_fd("\n", ms->exe.outfd);
	return (true);
}
