/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:25:24 by fwu               #+#    #+#             */
/*   Updated: 2024/12/22 20:19:32 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "tokenizing.h"
# include "parsing.h"
# include "error.h"

typedef struct s_minishell
{
	char	**envp;
}	t_minishell;

/* ****************************   BUILTINS   ****************************** */
// builtin.c
bool	builtin(t_minishell *ms);
// env.c
bool	ft_env(char *const envp[]);
// pwd.c
bool	ft_pwd(void);
// exit.c
bool	ft_exit(char *const argv[]);

/* ******************************   EXEC   ******************************** */
// exex.c
void	exec(void);

#endif //MINISHELL_H