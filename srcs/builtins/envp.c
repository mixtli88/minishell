/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:48:39 by fwu               #+#    #+#             */
/*   Updated: 2025/03/05 12:13:30 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	char 	*value;
	char 	*str2;
	int		i;

	i = 0;
	str2 = ft_strjoin(str, "=");
	while (envp && envp[i])
	{
		if(ft_strncmp(envp[i], str2, ft_strlen(str2)) == 0)
		{
			value =ft_strdup(ft_strchr(envp[i], '='));
			free(str2);
			return (value);
		}		
		i++;
	}
	free(str2);
	return (NULL);
}
