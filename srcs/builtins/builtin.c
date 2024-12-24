/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:04:56 by fwu               #+#    #+#             */
/*   Updated: 2024/12/23 21:46:48 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	builtin(t_minishell *ms)
{
	(void) ms;
	// ft_env(ms->envp);
	// ft_pwd();
	
	char *const argv[] = {"-n", "a", "b", "c", NULL};
	ft_echo(argv);
	return (true);
}
