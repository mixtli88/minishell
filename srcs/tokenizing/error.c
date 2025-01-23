/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:03:29 by mabril            #+#    #+#             */
/*   Updated: 2025/01/23 15:30:50 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_syntax(t_minishell *ms)
{
	t_data	*d;
	char	*strerror;

	strerror = NULL;
	d = &ms->data;
	if (!d->token_cur)
		strerror = "|";
	else if (ft_strncmp(d->token_cur->value, "|", 1) == 0)
		strerror = d->token_cur->value;
	else if (!d->token_cur->next)
		strerror = "newline";
	else if (d->token_cur->next->type != CMD)
		strerror = d->token_cur->next->value;
	printf("minishell: syntax error near unexpected token `%s'\n", strerror);
	ft_minishell_loop(ms);
}

void	error_path_cmd(t_cmd *cmd)
{
	printf("minishell: %s: command not found\n", cmd->argv[0]);
	exit(EXIT_FAILURE);
}

void	error_quote(t_minishell *ms)
{
	printf("Error, for closing quote\n");
	ft_minishell_loop(ms);
}

// void	error_directory(t_minishell *ms)
// {
// 	printf("minishell: %s: Is a directory\n", ms->exe.name);
// 	ft_minishell_loop(ms);
// }
