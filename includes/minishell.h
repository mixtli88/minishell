/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/01/06 21:09:02 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "tokenizing.h"


typedef struct s_command
{
	char **argv;
	char *cmd_path;
	char **evr;
	int input_fd;
	int output_fd;
	struct s_comand *next;
	
}	t_command;

/* ****************************   BUILTINS   ****************************** */
// builtin.c
void	builtin(void);

/* ******************************   EXEC   ******************************** */
// exex.c
void	exec(void);
void ft_minishell_loop(void);
// void ft_minishell_loop(int input_fd);
#endif //MINISHELL_H