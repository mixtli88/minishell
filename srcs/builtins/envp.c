/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:48:39 by fwu               #+#    #+#             */
/*   Updated: 2025/01/22 19:22:46 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// copy the original envp to another envp that you create
// you can store one more env or not(NULL)
char	**copy_envp(char **envp, char *env)
{
	char	**new_envp;
	int		i;

	i = 0;
	while (envp && envp[i])
		i++;
	if (!env)
		new_envp = (char **)ft_calloc(i + 1, sizeof(char *));
	else
		new_envp = (char **)ft_calloc(i + 1 + 1, sizeof(char *));
	if (!new_envp)
		return (NULL);
	i = 0;
	while (envp && envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	if (env)
		new_envp[i++] = ft_strdup(env);
	new_envp[i] = NULL;
	return (new_envp);
}

void	free_envp(char ***envp)
{
	int		i;

	i = 0;
	while (*envp && (*envp)[i])
	{
		free ((*envp)[i]);
		(*envp)[i] = NULL;
		i++;
	}
	if (*envp)
	{
		free (*envp);
		*envp = NULL;
	}
}

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
