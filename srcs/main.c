/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:36:57 by fwu               #+#    #+#             */
/*   Updated: 2025/01/04 17:30:08 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{ 
	(void) argc;
	(void) argv;
	(void) envp;
	// ft_putstr_fd("main\n", STDOUT_FILENO);
	ft_minishell_loop();
	
	
	
	return (0);
}
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
