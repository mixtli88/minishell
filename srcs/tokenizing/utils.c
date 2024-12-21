/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:00:16 by mabril            #+#    #+#             */
/*   Updated: 2024/12/20 18:44:57 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void init(t_token **list_token, char **av, bool flag)
// {
// 	int i;

// 	i = 0;
// 	while (av[i])
// 	{
// 		if (error_syntax(av[i]) == 1)
// 			error_free(list_token, av, flag);
// 		creat_token(&list_token, av[i]);
// 		i++;
// 	}
// 	if (flag)
// 		free_av(av);
// }