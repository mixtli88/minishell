/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:17:40 by fwu               #+#    #+#             */
/*   Updated: 2025/01/10 21:55:27 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_cd(char *argv[], char *envp[])
{
	(void) argv;

	// char *const oldpwd = "/Users/fwu/Documents/minishell";
	// char *const pwd = "/Users/fwu/Documents";
	int	i;

	i = 0;
	while (envp && envp[i])
	{
		// ft_putendl_fd(envp[i], STDOUT_FILENO);
		if (ft_strncmp(envp[i], "OLDPWD=", 7) == 0)
		{
			envp[i] = "OLDPWD=/Users/fwu/Documents/minishell";
			// ft_putendl_fd(envp[i], STDOUT_FILENO);
		}
		if (ft_strncmp(envp[i], "PWD=", 4) == 0)
		{
			envp[i] = "PWD=/Users/fwu/Documents";
			// ft_putendl_fd(envp[i], STDOUT_FILENO);
		}
		i++;
	}
	// ft_putendl_fd("correct", STDOUT_FILENO);	
	return (true);
}
