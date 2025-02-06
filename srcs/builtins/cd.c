/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:17:40 by fwu               #+#    #+#             */
/*   Updated: 2025/02/06 04:56:19 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


bool	ft_cd(t_minishell *ms, t_cmd *cmd)
{
	t_data	*d;

	d = &ms->data;
	ms->oldpwd_var.name = "OLDPWD";
	ms->oldpwd_var.operator = EQUAL;
	ms->oldpwd_var.value = ft_getenv("PWD", *(ms->envp));
	ms->pwd_var.name = "PWD";
	ms->pwd_var.operator = EQUAL;
	get_cd_path(ms, cmd);
	if (chdir(d->path) != 0)
		return (error_cd(cmd->argv[1]),false);
	ms->pwd_var.value = d->path; 
	if (!ms->pwd_var.value)
		return (error_cd(cmd->argv[1]), false);
	export_var(ms->oldpwd_var, ms->envp);
	export_var(ms->pwd_var, ms->envp);
	printf("entramos en cd\n");
	return (true);
}
