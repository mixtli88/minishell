/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 21:58:31 by fwu               #+#    #+#             */
/*   Updated: 2025/01/20 19:32:56 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getenv(char *str, char **envp)
{
	t_var	old_var;
	int		len_var;
	int		i;

	i = 0;
	while (envp && envp[i])
	{
		set_var(envp[i], EQUAL, &old_var);
		len_var = ft_strlen(old_var.name);
		if (ft_strncmp(str, old_var.name, len_var) == 0)
			return (old_var.value);
		free_var(&old_var);
		i++;
	}
	return (NULL);
}

bool	ft_pwd(char **argv, char **envp)
{
	(void) argv;
	char *env_pwd;

	env_pwd = ft_getenv("PWD", envp);
	if (!env_pwd)
	{
		ft_putendl_fd(ERR_PWD, STDERR_FILENO);
		return (false);
	}
	ft_putendl_fd(env_pwd, STDOUT_FILENO);
	return (true);
}
