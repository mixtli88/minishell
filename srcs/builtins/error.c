/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:29:45 by fwu               #+#    #+#             */
/*   Updated: 2025/01/23 01:59:50 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtin_error(char *builtin, char *err_arg, char *err_msg)
{
	ft_putstr_fd(builtin, STDOUT_FILENO);
	ft_putstr_fd(": ", STDOUT_FILENO);
	if (err_arg)
	{
		ft_putstr_fd(err_arg, STDOUT_FILENO);
		ft_putstr_fd(": ", STDOUT_FILENO);		
	}
	ft_putendl_fd(err_msg, STDOUT_FILENO);
}

void error_cd(char *str)
{
    printf("minishell: cd: %s: No such file or directory\n", str);  
}
