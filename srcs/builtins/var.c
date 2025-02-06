/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:17:40 by fwu               #+#    #+#             */
/*   Updated: 2025/01/31 11:20:17 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ini_var(t_var *var)
{
	var->name = NULL;
	var->value = NULL;
	var->operator = NULL;
}

void	free_var(t_var *var)
{
	if (var->name)
	{
		free(var->name);
		var->name = NULL;
	}
	if (var->value)
	{
		free(var->value);
		var->value = NULL;
	}
	if (var->value)
	{
		free(var->value);
		var->value = NULL;
	}
}

bool	set_var(char *format, char *operator, t_var *var)
{
	char	*occurrence;
	int		pos_occ;
	int		len_format;

	ini_var(var);
	len_format = ft_strlen(format);
	occurrence = ft_strnstr(format, operator, len_format);
	if (!occurrence)
	{
		var->name = ft_strdup(format);
		return (false);
	}
	pos_occ = occurrence - format;
	var->name = ft_substr(format, 0, pos_occ);
	var->operator = operator;
	if (ft_strncmp(operator, EQUAL, len_format) == 0)
		var->value = ft_substr(format, pos_occ + 1, len_format);
	else if (ft_strncmp(operator, PLAS_EQUAL, len_format) == 0)
		var->value = ft_substr(format, pos_occ + 2, len_format);
	return (true);
}

bool	check_var(t_var var)
{
	int	i;

	i = 0;
	while (var.name && var.name[i])
	{
		if ((i == 0) && ft_isdigit(var.name[i]))
			return (false);
		if (!(var.name[i] == '_' || ft_isalnum(var.name[i])))
			return (false);
		i++;
	}
	if (i == 0)
		return (false);
	return (true);
}

	// ft_putendl_fd(var->name, STDOUT_FILENO);
	// ft_putendl_fd(var->operator, STDOUT_FILENO);
	// ft_putendl_fd(var->value, STDOUT_FILENO);
bool	find_var(char *format, t_var *var)
{
	if (!set_var(format, PLAS_EQUAL, var))
	{
		free_var(var);
		set_var(format, EQUAL, var);
	}
	if (!check_var(*var))
	{
		free_var(var);
		builtin_error(EXPORT, format, ERR_NOT_VAILD_IDENTIFIER);
		return (false);
	}
	if (!var->operator)
	{
		free_var(var);
		return (false);
	}
	return (true);
}