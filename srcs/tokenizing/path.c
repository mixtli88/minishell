/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:10:39 by mike              #+#    #+#             */
/*   Updated: 2025/01/21 14:53:21 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	find_path(t_minishell *ms)
{
	char	**paths;
	int		i;
	t_data	*d;

	d = &ms->data;
	i = -1;
	paths = ft_split(getenv("PATH"), ':');
	if (not_path(ms))
		return ;
	while (paths[++i])
	{
		free(d->full_path);
		d->full_path = ft_strjoin(ft_strjoin(paths[i], "/"),
				d->token_cur->value);
		if (access(d->full_path, X_OK) == 0)
		{
			d->cur_cmd->path = ft_strdup(d->full_path);
			free_table(paths);
			return ;
		}
	}
	free_table(paths);
	error_path_cmd(ms);
}

int	not_path(t_minishell *ms)
{
	int		phind;
	char	*str;

	phind = 0;
	str = ms->data.token_cur->value;
	if (ft_strcmp(str, "cd") == 0 || ft_strcmp(str, "echo") == 0
		|| ft_strcmp(str, "env") == 0 || ft_strcmp(str, "envp") == 0
		|| ft_strcmp(str, "error") == 0 || ft_strcmp(str, "exit") == 0
		|| ft_strcmp(str, "export") == 0 || ft_strcmp(str, "pwd") == 0)
	{
		ms->data.cur_cmd->path = NULL;
		phind = 1;
	}
	if (ft_strncmp(ms->data.token_cur->value, "", 1) == 0)
		error_path_cmd(ms);
	if (ft_strncmp(ms->data.token_cur->value, "/", 1) == 0)
		error_directory(ms);
	if (ft_strncmp(ms->data.token_cur->value, "!", 1) == 0)
		error_syntax(ms);
	if (ft_strncmp(ms->data.token_cur->value, ":", 1) == 0)
		ft_minishell_loop(ms);
	if (ft_strncmp(ms->data.token_cur->value, "|", 1) == 0)
		ft_minishell_loop(ms);
	return (phind);
}

// cd
// echo
// env
// envp
// error
// exit
// export
// pwd
// var
