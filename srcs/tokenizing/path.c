/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:10:39 by mike              #+#    #+#             */
/*   Updated: 2025/01/15 03:08:07 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void find_path(t_data **data)
{
    char **paths;
    char *full_path;
    int i;
    
    i = 0;
    paths = ft_split(getenv("PATH"), ':');
    while(paths[i])
    {
        full_path = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(full_path, (*data)->cmd_list->argv[i]);
        if(access(full_path, X_OK))
        {
            free_table(paths);
            retun(full_path);
        }
        free(full_path);
        i++;
    }
    free_table(paths);
    // mensaje de error;
    error_free(data);
}   