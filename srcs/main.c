/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:36:57 by fwu               #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/23 21:23:38 by fwu              ###   ########.fr       */
=======
/*   Updated: 2025/01/06 21:44:00 by mabril           ###   ########.fr       */
>>>>>>> 51711d4e88fb38d5244072e310da912991e24978
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

<<<<<<< HEAD
int	main(int argc, char *argv[], char *envp[])
{
	static t_minishell	ms;
	
	(void) argc;
	(void) argv;
	(void) envp;
	ms.envp = envp;
	builtin(&ms);
	return (0);
}
=======


// int	main(int argc, char **argv, char **envp)
// {
// 	(void) envp;
// 	int input_fd = STDIN_FILENO; // Por defecto, leerá de stdin (terminal)

// 	// Comprobar si se pasa un archivo como argumento
// 	if (argc > 1)
// 	{
// 		input_fd = open(argv[1], O_RDONLY);
// 		if (input_fd == -1)
// 		{
// 			perror("Error abriendo el archivo");
// 			return (1);
// 		}
// 	}

// 	// Si se pasa un archivo, lee de input_fd en lugar de readline
// 	ft_minishell_loop(input_fd);

// 	// Cerrar el archivo si fue abierto
// 	if (input_fd != STDIN_FILENO)
// 		close(input_fd);

// 	return (0);
// }
>>>>>>> 51711d4e88fb38d5244072e310da912991e24978
