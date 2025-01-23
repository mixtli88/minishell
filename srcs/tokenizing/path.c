/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:10:39 by mike              #+#    #+#             */
/*   Updated: 2025/01/23 17:25:39 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_path(t_minishell *ms)
{
	char	**paths;
	int		i;
	t_data	*d;

	d = &ms->data;
	i = -1;
	paths = ft_split(getenv("PATH"), ':');
	while (paths[++i])
	{
		free(d->full_path);
		d->full_path = ft_strjoin(ft_strjoin(paths[i], "/"), d->token_cur->value);
		if (access(d->full_path, X_OK) == 0)
			return(free_table(paths), 1) ;
	}
	return(free_table(paths), 0);
}

// int	not_path(t_minishell *ms)
// {
// 	int		phind;
// 	char	*str;

// 	phind = 0;
// 	str = ms->data.token_cur->value;
// 	// if (ft_strncmp(ms->data.token_cur->value, "", 1) == 0)
// 	// 	error_path_cmd(ms, cmd);
// 	if (ft_strncmp(ms->data.token_cur->value, "/", 1) == 0)
// 		error_directory(ms);
// 	if (ft_strncmp(ms->data.token_cur->value, "!", 1) == 0)
// 		error_syntax(ms);
// 	if (ft_strncmp(ms->data.token_cur->value, ":", 1) == 0)
// 		ft_minishell_loop(ms);
// 	// if (ft_strncmp(ms->data.token_cur->value, "|", 1) == 0)
// 	// 	ft_minishell_loop(ms);
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
