/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/02/19 13:53:48 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "parsing.h"
# include "execution.h"
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>
#include <errno.h> 
// #include <bits/sigaction.h>
extern int g_signal_status;
/* ******************************   MAIN   ******************************** */
void ft_minishell_loop(t_minishell	*ms);

#endif //MINISHELL_H