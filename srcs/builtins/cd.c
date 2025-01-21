/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:17:40 by fwu               #+#    #+#             */
/*   Updated: 2025/01/20 20:11:16 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// only finish absolute path
bool	ft_cd(char **argv, char ***envp)
{
	t_var	oldpwd_var;
	t_var	pwd_var;

	oldpwd_var.name = "OLDPWD";
	oldpwd_var.operator = EQUAL;
	oldpwd_var.value = ft_getenv("PWD", *envp);
	pwd_var.name = "PWD";
	pwd_var.operator = EQUAL;
	pwd_var.value = argv[1];
	export_var(oldpwd_var, envp);
	export_var(pwd_var, envp);
	return (true);
}
