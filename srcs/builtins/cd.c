/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:17:40 by fwu               #+#    #+#             */
/*   Updated: 2025/01/24 11:20:59 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_cd(char **argv, char ***envp)
{
	t_var	oldpwd_var;
	t_var	pwd_var;
	char	*path;
	char *last_slash;

	oldpwd_var.name = "OLDPWD";
	oldpwd_var.operator = EQUAL;
	oldpwd_var.value = ft_getenv("PWD", *envp);
	pwd_var.name = "PWD";
	pwd_var.operator = EQUAL;
	if (!argv[1])
		path = ft_getenv("HOME", *envp);
	else if (ft_strcmp(argv[1], ".") == 0)
		path = ft_strdup(oldpwd_var.value);
	else if (ft_strcmp(argv[1], "..") == 0)
	{
		last_slash = ft_strrchr(oldpwd_var.value, '/');
		if (last_slash && last_slash != oldpwd_var.value)
		{
			*last_slash = '\0';
			path = ft_strdup(oldpwd_var.value);
		} 
	}
	else if (argv[1][0] == '/')
		path = ft_strdup(argv[1]);
	else
		path = ft_strjoin(ft_strjoin(oldpwd_var.value, "/"), argv[1]);
	if (chdir(path) != 0)
	{ 
		error_cd(argv[1]);
		free(path);
		return (false);
	}
	pwd_var.value = path;
	if (!pwd_var.value)
		return (error_cd(argv[1]), false);
	export_var(oldpwd_var, envp);
	export_var(pwd_var, envp);
	return (true);
}
