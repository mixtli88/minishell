/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:36:57 by fwu               #+#    #+#             */
/*   Updated: 2025/01/19 14:09:56 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	static t_minishell	ms;

	(void)argc;
	(void)argv;
	ms.envp = copy_envp(envp, NULL);
	ft_minishell_loop(&ms);
	// builtin(&ms);	
	return (0);
}

// 0 < "infile"
// 1 > "output"
// 2 << "limiter" 
// 3 >> "output"
