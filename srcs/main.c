/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:36:57 by fwu               #+#    #+#             */
/*   Updated: 2025/03/06 11:19:39 by mike             ###   ########.fr       */
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
	get_user_uid(&ms);
	ft_minishell_loop(&ms);
	return (0);
}
