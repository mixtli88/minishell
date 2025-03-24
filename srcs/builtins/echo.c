/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:17:40 by fwu               #+#    #+#             */
/*   Updated: 2025/03/24 12:46:29 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// echo          => '\n'
// echo abc      => abc'\n'
// echo a b c    => a b c'\n'
// echo -n       => ''
// echo -n abc   => abc
// echo -n a b c => a b c
void	print_args(t_minishell *ms, int i)
{
	while (ms->exe.argv && ms->exe.argv[i])
	{
		ft_putstr_fd(ms->exe.argv[i], ms->exe.outfd);
		if (ms->exe.argv[i + 1])
			ft_putstr_fd(" ", ms->exe.outfd);
		i++;
	}
}

bool	ft_echo(t_minishell *ms)
{
	bool	flag_new_line;
	int		i;
	int		j;

	j = 2;
	flag_new_line = true;
	i = 1;
	while (ms->exe.argv[i] && ft_strncmp(ms->exe.argv[i], "-n", 2) == 0)
	{
		while (ms->exe.argv[i][j] == ms->exe.argv[i][j - 1])
			j++;
		if(ms->exe.argv[i][j] == '\0')
			flag_new_line = false;
		else
			break;
		i++;
	}
	print_args(ms, i);
	if (flag_new_line)
		ft_putstr_fd("\n", ms->exe.outfd);
	ms->status = 0;
	return (true);
}
