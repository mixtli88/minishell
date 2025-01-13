/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/01/19 12:34:30 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "builtin.h"
# include "tokenizing.h"
# include "error.h"

typedef struct s_minishell
{
	char	**envp;
}	t_minishell;

typedef struct s_command
{
	char **argv;
	char *cmd_path;
	char **evr;
	int input_fd;
	int output_fd;
	struct s_comand *next;
	
}	t_command;

/* ******************************   EXEC   ******************************** */
// exex.c
void	exec(void);
void ft_minishell_loop(t_minishell	*ms);
// void ft_minishell_loop(int input_fd);
#endif //MINISHELL_H