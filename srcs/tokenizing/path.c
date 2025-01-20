/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:10:39 by mike              #+#    #+#             */
/*   Updated: 2025/01/19 20:17:12 by mabril           ###   ########.fr       */
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
	// if(not_path(ms))
	// 	return;
	while (paths[++i])
	{
		d->path_w_slash = ft_strjoin(paths[i], "/");
		d->full_path = ft_strjoin(d->path_w_slash, (d->token_cur->value));
		free(d->path_w_slash);
		d->path_w_slash = NULL;
		if (access(d->full_path, X_OK) == 0)
		{
			d->cur_cmd->path = ft_strdup(d->full_path);
			free_table(paths);
			paths = NULL;
			return ;
		}
		free(d->full_path);
		d->full_path = NULL;
	}
	free_table(paths);
	error_path_cmd(ms);
}
// int not_path(t_minishell *ms)
// {
// 	int phind;
// 	char *str;

// 	phind = 0;
// 	str = ms->data.token_cur->value;
// 	if(str == "cd" || str == "echo"|| str == "env" || str == "envp" || str == "error" || str == "exit" || str == "export" || str == "pwd" || str == "var")
// 	{
// 		ms->data.cur_cmd->path = NULL;
// 		phind = 1;
// 	}
// 	return (phind);
// }

// cd 
// echo
// env 
// envp 
// error 
// exit 
// export 
// pwd 
// var 
