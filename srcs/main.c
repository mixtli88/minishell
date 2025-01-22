/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:36:57 by fwu               #+#    #+#             */
/*   Updated: 2025/01/21 23:48:14 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	static t_minishell	ms;

	(void)argc;
	(void)argv;
	ms.envp =envp;
	ft_minishell_loop(&ms);
	return (0);
}
