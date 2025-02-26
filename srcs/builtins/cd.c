/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:17:40 by fwu               #+#    #+#             */
/*   Updated: 2025/02/20 02:19:03 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


// bool	ft_cd(t_minishell *ms, t_cmd *cmd)
// {
// 	t_data	*d;

// 	d = &ms->data;
// 	ms->oldpwd_var.name = "OLDPWD";
// 	ms->oldpwd_var.operator = EQUAL;
// 	ms->oldpwd_var.value = ft_getenv("PWD", *(ms->envp));
// 	ms->pwd_var.name = "PWD";
// 	ms->pwd_var.operator = EQUAL;
// 	get_cd_path(ms, cmd);
// 	if (chdir(d->path) != 0)
// 		return (error_cd(cmd->argv[1]),false);
// 	ms->pwd_var.value = d->path; 
// 	if (!ms->pwd_var.value)
// 		return (error_cd(cmd->argv[1]), false);
// 	export_var(ms->oldpwd_var, ms->envp);
// 	export_var(ms->pwd_var, ms->envp);
// 	printf("entramos en cd\n");
// 	return (true);
// }

bool is_directory(const char *path, int *err)
{
	struct stat statbuf;
	
	if (stat(path, &statbuf) != 0)
	{
		*err = errno;
		return false;
	}
	if (!(statbuf.st_mode & S_IFDIR))
    {
        *err = ENOTDIR;
        return false;
    }
	return true;  
}

bool	ft_cd(t_minishell *ms, t_cmd *cmd)
{
	t_data	*d;
	int err;
	
	d = &ms->data;
	ms->oldpwd_var.name = "OLDPWD";
	// falta verificar si es un archivo o caperta
	ms->oldpwd_var.operator = EQUAL;
	ms->oldpwd_var.value = ft_getenv("PWD", *(ms->envp));
	ms->pwd_var.name = "PWD";
	ms->pwd_var.operator = EQUAL;
	get_cd_path(ms, cmd);
	if (!is_directory(d->path, &err) || chdir(d->path) != 0)
	{
		if (errno == ENOTDIR)
        	err = errno;
		error_cd(cmd->argv[1], err);
		free(d->path);	
		return (false);
	}
	ms->pwd_var.value = d->path;
	export_var(ms->oldpwd_var, ms->envp);
	export_var(ms->pwd_var, ms->envp);
	return (true);
}
