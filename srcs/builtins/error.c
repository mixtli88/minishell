/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:29:45 by fwu               #+#    #+#             */
/*   Updated: 2025/01/11 22:53:16 by fwu              ###   ########.fr       */
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
