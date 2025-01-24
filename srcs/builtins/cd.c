/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:17:40 by fwu               #+#    #+#             */
/*   Updated: 2025/01/24 00:56:56 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// only finish absolute path
// bool	ft_cd(char **argv, char ***envp)
// {
// 	t_var	oldpwd_var;
// 	t_var	pwd_var;

// 	oldpwd_var.name = "OLDPWD";
// 	oldpwd_var.operator = EQUAL;
// 	oldpwd_var.value = ft_getenv("PWD", *envp);
// 	pwd_var.name = "PWD";
// 	pwd_var.operator = EQUAL;
// 	pwd_var.value = argv[1];
// 	export_var(oldpwd_var, envp);
// 	export_var(pwd_var, envp);
// 	return (true);
// // }

bool	ft_cd(char **argv, char ***envp)
{
	t_var	oldpwd_var;
	t_var	pwd_var;
	char	*path;
	// char	*;

	oldpwd_var.name = "OLDPWD";
	oldpwd_var.operator = EQUAL;
	oldpwd_var.value = ft_getenv("PWD", *envp);
	printf("%s", oldpwd_var.value);
	pwd_var.name = "PWD";
	pwd_var.operator = EQUAL;
	if (!argv[1])
	{
		path = ft_getenv("HOME", *envp);
	}
	// else if (argv[1][0] == '..')
	// {
		
	// }
	// 	path = ft_strdup(argv[1]);
	else if (argv[1][0] == '/')
		path = ft_strdup(argv[1]);
	else
		path = ft_strjoin(ft_strjoin(oldpwd_var.value, "/"), argv[1]);
	if (chdir(path) != 0)
	{ 
	printf("%s\n", "entramos");	
		error_cd(argv[1]);
		free(path);
		return (false);
	}
	pwd_var.value = path;
	if (!pwd_var.value)
		return (error_cd(argv[1]), false);
	export_var(oldpwd_var, envp);
	export_var(pwd_var, envp);
	return (true);
}

//     t_var   oldpwd_var;
//     t_var   pwd_var;
//     // char	*path;
// 	int i =0;
//     oldpwd_var.name = "OLDPWD";
//     oldpwd_var.operator = EQUAL; //     oldpwd_var.value = getenv("PWD");

//     pwd_var.name = "PWD";
//     pwd_var.operator = EQUAL;
//     if(!argv[1])
//         pwd_var.value = ft_getenv("HOME", *envp);
//     else if(argv[1][0] != '/')
//     {
// 		pwd_var.value = argv[1];
// 	}
// 	else
// 	{
// 		path = ft_strjoin(oldpwd_var.value, "/");
//         path = ft_strcat(&path, &argv[1]);
// 		pwd_var.value = path;
//     }
// 	oldpwd_var.value = getpwd("PWD");

// 		// printf("%s******\n", oldpwd_var.value);
// 		getpwd("OLDPWD");
//     chdir();
//    		printf("%d******\n", i);

//     if (i != 0)
// 	{
// error_cd(argv[1]);
// 		return(false);
// 	}
//     export_var(oldpwd_var, envp);
//     export_var(pwd_var, envp);
//     return (true);
// }

// bool ft_cd(char **argv, char ***envp) {
//     t_var oldpwd_var;
//     t_var pwd_var;
//     char *new_path;
//     char *current_dir;
//     struct stat statbuf;

//     // Configurar las variables OLD y PWD
//     oldpwd_var.name = "OLDPWD";
//     oldpwd_var.operator = EQUAL;
//     oldpwd_var.value = ft_strdup(ft_getenv("PWD", *envp));

//     pwd_var.name = "PWD";
//     pwd_var.operator = EQUAL;

//     // Resolver el nuevo directorio
//     if (!argv[1]) {
//         // Sin argumentos, usar HOME
//         new_path = ft_strdup(ft_getenv("HOME", *envp));
//         if (!new_path) {
//             error_cd("HOME not set");
//             return (false);
//         }
//     } else if (ft_strcmp(argv[1], "..") == 0) {
//         // Ir al directorio padre
//         char *last_slash = ft_strrchr(oldpwd_var.value, '/');
//         if (last_slash && last_slash != oldpwd_var.value) {
//             *last_slash = '\0'; // Eliminar la última parte del path
//             new_path = ft_strdup(oldpwd_var.value);
//         } else {
//             new_path = ft_strdup("/");
//         }
//     } else if (ft_strcmp(argv[1], ".") == 0) {
//         // Permanecer en el directorio actual
//         new_path = ft_strdup(oldpwd_var.value);
//     } else {
//         // Rutas relativas o absolutas
//         if (argv[1][0] == '/') {
//             // Ruta absoluta
//             new_path = ft_strdup(argv[1]);
//         } else {
//             // Ruta relativa
//             current_dir = getcwd(NULL, 0);
//             new_path = ft_strjoin(ft_strjoin(current_dir, "/"), argv[1]);
//             free(current_dir);
//         }
//     }

//     // Validar si el nuevo directorio existe
//     if (stat(new_path, &statbuf) != 0 || !S_ISDIR(statbuf.st_mode)) {
//         error_cd(argv[1]);
//         free(new_path);
//         return (false);
//     }

//     // Cambiar al nuevo directorio
//     if (chdir(new_path) != 0) {
//         error_cd(argv[1]);
//         free(new_path);
//         return (false);
//     }

//     // Actualizar las variables de entorno
//     pwd_var.value = getcwd(NULL, 0);
	// Obtener el directorio actual después del cambio
//     export_var(oldpwd_var, envp);
//     export_var(pwd_var, envp);

//     free(new_path);
//     return (true);
// }
