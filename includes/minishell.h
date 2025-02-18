/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2025/02/18 11:55:49 by mike             ###   ########.fr       */
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
// #include <bits/sigaction.h>
extern int g_signal_status;
/* ******************************   MAIN   ******************************** */
void ft_minishell_loop(t_minishell	*ms);

#endif //MINISHELL_H