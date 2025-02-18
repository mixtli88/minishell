/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exe2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:06:19 by fwu               #+#    #+#             */
/*   Updated: 2025/02/10 11:48:54 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_int_double(t_minishell *ms)
{
	int	i;

	i = 0;
	while (i < ms->fd.pipe_num)
	{
		free(ms->fd.pipe[i]);
		ms->fd.pipe[i] = NULL;
		i++;
	}
	free(ms->fd.pipe);
	ms->fd.pipe = NULL;
}

void	reset_t_fd(t_minishell *ms)
{
	if (ms->fd.pipe)
		free_int_double(ms);
	ms->fd.cmd_num = 0;
	ms->fd.infile = 0;
	ms->fd.outfile = 0;
	ms->fd.pipe_num = 0;
}
