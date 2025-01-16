/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2025/01/15 22:26:34 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_type type_token(char *token)
{
	if (ft_strncmp(token, "|", 1) == 0)
		return(PIPE);
	else if (ft_strncmp(token, ">", 1) == 0)
		return(REDIR);
	else if (ft_strncmp(token, "<", 1) == 0)
		return(REDIR);
	else if (ft_strncmp(token, ">>", 1) == 0)
		return(REDIR);
	else if (ft_strncmp(token, "<<", 1) == 0)
		return(REDIR);
	else if (token[0] == '$')
		return(VARIABLE);
	else 
		return(CMD);
	
}
void creat_token(t_data **data)
{
	t_data *d;
	t_token *new;
	t_token *last;
	
	d = *data;	
	last = NULL;
	new = malloc(sizeof (t_token));
	init_new_token(data, &new);
	new->next = NULL;
	if(d->tok_list == NULL)
		d->tok_list = new;
	else
	{
		last = d->tok_list;
		while(last->next != NULL)
			last = last->next;
		last->next = new;
	}	
}

void lexer(t_data **data)
{
	t_token *tok_curr;
	t_cmd *cmd_curr;
	
	int i = 0 ;
	split_input(data);
	buil_cmd_list(data);
	cmd_curr = (*data)->cmd_list;
	tok_curr = (*data)->tok_list;
	while (tok_curr)
	{
		printf(" *%u* %s [%d] ->", tok_curr->type, tok_curr->value, i);
		tok_curr = tok_curr->next;
		i++;
	} 
	printf("\n\n***** list.token **** \n");
	
	int j = 0;
	while (cmd_curr)
	{	
		i = 0;
		printf("\ncmd [%d] \narg -> = {", j);
		while (cmd_curr->argv[i])
		{
			printf(" \"%s\"", cmd_curr->argv[i]);
			if(cmd_curr->argv[i + 1])
				printf(",");
			else
				printf(" }\n");
			i++;
		}
		printf("fd = { \"%s\" }\n", cmd_curr->fd_rdir);
		printf("redi = {%d}\n", cmd_curr->rdir);
		cmd_curr = cmd_curr->next;
		j++;
	}
	printf("\n");
}

void ft_minishell_loop(char **envp)
{
	t_data *data;
	
	data = NULL;
    while (1)
	{
		if(data == NULL)
			data = ft_calloc(sizeof(t_data),1);
		data->envp = envp;	
        data->input = readline("minishell$ ");
        if (!data->input)
            break;
        if (strcmp(data->input, "exit") == 0) 
		{
            printf("exit\n");
            error_free(&data);
			break;
        }
        if (data->input)
            add_history(data->input);
		init_data(&data);
		lexer(&data);
		// tokenizing();
	    if(data)
			error_free(&data);
    }
}


// void ft_minishell_loop(int input_fd)
// {
//     t_data *data;
//     char buffer[1024];
//     ssize_t bytes_read;

//     data = ft_calloc(1, sizeof(t_data));

//     while (1)
//     {
//         if (data == NULL)
//             data = ft_calloc(1, sizeof(t_data));

//         if (input_fd == STDIN_FILENO)
//         {
//             // Entrada interactiva
//             data->input = readline("minishell$ ");
//             if (!data->input) // EOF o Ctrl+D
//                 break;
//             if (*data->input)
//                 add_history(data->input);
//         }
//         else
//         {
//             // Leer del archivo
//             bytes_read = read(input_fd, buffer, sizeof(buffer) - 1);
//             if (bytes_read <= 0)
//                 break; // EOF o error
//             buffer[bytes_read] = '\0'; // Asegurar que sea un string
//             data->input = strdup(buffer); // Copiar buffer a input
//         }

//         if (strcmp(data->input, "exit\n") == 0 || strcmp(data->input, "exit") == 0)
//         {
//             printf("exit\n");
//             free(data->input);
//             free(data);
//             break;
//         }

//         ft_init_data(&data);
//         lexer(&data);

//         free(data->input);
//         free(data);
//         data = NULL;
//     }
// }


        // printf("Entrada recibida: %s\n", data->input);
		// printf("1\n");
		// printf("2\n");
		// printf(" head %p\n", head);
		// printf(" act %p\n", act);