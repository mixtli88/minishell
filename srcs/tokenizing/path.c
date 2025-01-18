/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:10:39 by mike              #+#    #+#             */
/*   Updated: 2025/01/17 23:13:48 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void find_path(t_minishell	*ms, t_data **data)
{
    char **paths;
    int i;
    
    i = -1;
    paths = ft_split(getenv("PATH"), ':');
    while(paths[++i])
    {	
        (*data)->path_w_slash = ft_strjoin(paths[i], "/");
        (*data)->full_path = ft_strjoin((*data)->path_w_slash, ((*data)->cur_cmd->argv[0]));
		free((*data)->path_w_slash);
		(*data)->path_w_slash = NULL;
	    if(access((*data)->full_path, X_OK) == 0)
        {
            (*data)->cur_cmd->path = ft_strdup((*data)->full_path);
            free_table(paths);
			paths = NULL;
			free((*data)->full_path);
			(*data)->full_path = NULL;
            return;
        }
        free((*data)->full_path);
    }
    free_table(paths);
    error_path_cmd(ms, data);
}   
