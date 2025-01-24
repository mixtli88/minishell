/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:17:40 by fwu               #+#    #+#             */
/*   Updated: 2025/01/24 09:33:37 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// echo          => '\n'
// echo abc      => abc'\n'
// echo a b c    => a b c'\n'
// echo -n       => ''
// echo -n abc   => abc
// echo -n a b c => a b c
bool	ft_echo(char **argv)
{
	// ft_putendl_fd("echo", STDOUT_FILENO);
	bool	flag_new_line;
	int		i;

	flag_new_line = true;
	i = 1;
	while (argv && argv[i])
	{
		if (i == 1 && ft_strncmp(argv[i], "-n", 2) == 0)
			flag_new_line = false;
		else
		{
			ft_putstr_fd(argv[i], STDOUT_FILENO);
			if (argv[i + 1])
				ft_putstr_fd(" ", STDOUT_FILENO);
		}
		i++;
	}
	if (flag_new_line)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (true);
}
