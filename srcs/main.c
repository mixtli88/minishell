/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:36:57 by fwu               #+#    #+#             */
/*   Updated: 2025/01/22 17:51:46 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	(void)argv;	
	static t_minishell	ms;
	char **tmp_envp;

	tmp_envp = copy_envp(envp, NULL);
	ms.envp = &tmp_envp;
	ft_minishell_loop(&ms);
	return (0);
}
