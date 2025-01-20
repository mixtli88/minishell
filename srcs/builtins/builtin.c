/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:04:56 by fwu               #+#    #+#             */
/*   Updated: 2025/01/19 16:43:23 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	builtin(t_minishell *ms)
{
	(void) ms;
	// ft_pwd();
	
	char *argv[] = {"c=", "ss1=2", NULL};
	ft_export(argv, &(ms->envp));
	// char *argv2[] = {"s=5", NULL};
	// ft_export(argv2, &(ms->envp));
	ft_env(ms->envp);

	// ft_echo(argv);
	// ft_cd(argv, ms->envp);

	// char *argv2[] = {"/bin/ls", NULL};
	// char *path = "/bin/ls";
	// execve(path, argv2, ms->envp);
	return (true);
}
