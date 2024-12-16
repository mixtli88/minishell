/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2024/12/16 17:38:14 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int get_tokend(char *token)
{
	if (ft_strcmp(token, "|") == 0)
		return(TOKEN_PIPE);
	else if (ft_strncmp(token, ">", 1) == 0 ||  ft_strncmp(token, "<", 1) == 0)
		return(TOKEN_PIPE);
	else if (ft_strncmp(token, ";", 1) == 0)
		return(TOKEN_SEPARATOR);
	else if (ft_strncmp(token, "&", 1 ) == 0)
		return(TOKEN_BACKGROUND);
	else if (token[0] == '$')
		return(TOKEN_VARIABLE);
	else ((*token))
		return(TOKEN_PIPE);
	
}
void	tokenizing(int argc, char *argv[], char *envp[])
{
	ft_putstr_fd("tokenizing\n", STDOUT_FILENO);
	if (argc == 2)
	{
		argv = ft_split(argv[2], " ");	
	}	
}
