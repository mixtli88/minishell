/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:17:40 by fwu               #+#    #+#             */
/*   Updated: 2025/02/19 12:53:20 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_var(t_var new_var, char ***envp)
{
	char	**new_envp;
	char	*tmp;
	char	*env;

	tmp = ft_strjoin(new_var.name, EQUAL);
	env = ft_strjoin(tmp, new_var.value);
	new_envp = copy_envp(*envp, env);
	free_envp(envp);
	*envp = new_envp;
	free (tmp);
	free (env);
}

void	mod_var(t_var new_var, t_var old_var, char **envp)
{
	char	*tmp;
	char	*env;
	
	env = NULL;
	if (ft_strncmp(new_var.operator, EQUAL, 1) == 0)
	{
		tmp = ft_strjoin(new_var.name, EQUAL);
		env = ft_strjoin(tmp, new_var.value);
		free (tmp);
	}
	else if (ft_strncmp(new_var.operator, PLAS_EQUAL, 2) == 0)
	{
		tmp = ft_strjoin(new_var.name, EQUAL);
		env = ft_strjoin(tmp, old_var.value);
		free (tmp);
		tmp = ft_strjoin(env, new_var.value);
		free (env);
		env = tmp;
	}
	free (*envp);
	*envp = env;
}

void	export_var(t_var new_var, char ***envp)
{
	t_var	old_var;
	// int		len_var;
	int		i;

	i = 0;
	while (*envp && (*envp)[i])
	{
		set_var((*envp)[i], EQUAL, &old_var);
		// len_var = ft_strlen(old_var.name);
		if (ft_strcmp(new_var.name, old_var.name) == 0)
		{
			mod_var(new_var, old_var, &((*envp)[i]));
			free_var(&old_var);
			return ;
		}
		free_var(&old_var);
		i++;
	}
	add_var(new_var, envp);
}

void	ft_export(t_minishell *ms, char **argv, char ***envp)
{
	t_var	new_var;	
	int	i;

	i = 1;
	while (argv && argv[i])
	{
		if (find_var(argv[i], &new_var))
		{
			export_var(new_var, envp);
			free_var(&new_var);
		}
		i++;
	}
	ms->status = 0;
}
