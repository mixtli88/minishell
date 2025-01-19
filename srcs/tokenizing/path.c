/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:10:39 by mike              #+#    #+#             */
/*   Updated: 2025/01/18 23:16:00 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void find_path(t_minishell	*ms)
{
    char **paths;
    int i;
    t_data *d;
	
	d = &ms->data;
    i = -1;
    paths = ft_split(getenv("PATH"), ':');
    while(paths[++i])
    {	
        d->path_w_slash = ft_strjoin(paths[i], "/");
        d->full_path = ft_strjoin(d->path_w_slash, (d->cur_cmd->argv[0]));
		free(d->path_w_slash);
		d->path_w_slash = NULL;
	    if(access(d->full_path, X_OK) == 0)
        {
            d->cur_cmd->path = ft_strdup(d->full_path);
            free_table(paths);
			paths = NULL;
			free(d->full_path);
			d->full_path = NULL;
            return;
        }
        free(d->full_path);
		d->full_path = NULL;
    }
    free_table(paths);
    error_path_cmd(ms);
}   
