/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2025/01/05 00:43:59 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_init_data(t_data **data)
{
	(*data)->buf_idx = 0;
	(*data)->i = 0;
	(*data)->quote = 0;
	(*data)->tok_list = NULL;
	(*data)->tem = ft_strdup("");
	(*data)->add_input = ft_strdup("");
	(*data)->new_line = ft_strdup("");
}
t_type type_token(char *token)
{
	if (ft_strncmp(token, "|", 1) == 0)
		return(PIPE);
	else if (ft_strncmp(token, ">", 1) == 0)
		return(REDIR_IN);
	else if (ft_strncmp(token, "<", 1) == 0)
		return(REDIR_OUT);
	else if (ft_strncmp(token, ">>", 1) == 0)
		return(REDIR_OUT);
	else if (ft_strncmp(token, "<<", 1) == 0)
		return(REDIR_OUT);
	else if (ft_strncmp(token, ";", 1) == 0)
		return(SEPARATOR);
	else if (ft_strncmp(token, "&", 1 ) == 0)
		return(BACKGROUND);
	else if (token[0] == '$')
		return(VARIABLE);
	else if (ft_isalpha(token[0]))
		return(WORLD);
	else 
		return(TOKEN_INVALID);
	
}
void creat_token(t_data **data)
{
	t_token *new;
	t_token *last;
		
	new = malloc(sizeof (t_token));
	last = NULL;
	new->value = ft_strdup((*data)->buff);
	new->type = type_token((*data)->buff);
	if((*data)->quote == '"')
		new->quote = 2;
	else if((*data)->quote == '\'')
		new->quote = 1;	
	else
		new->quote = 0;
	new->next = NULL;
	if((*data)->tok_list == NULL)
		(*data)->tok_list = new;
	else
	{
		last = (*data)->tok_list;
		while(last->next != NULL)
			last = last->next;
		last->next = new;
	}	
	(*data)->buf_idx = 0;
	(*data)->quote = 0;
}

void lexer(t_data **data)
{
	// int i;
	t_token *cur;

	// i = 0;
	split_input(data);
	cur = (*data)->tok_list;
	while (cur)
	{
		printf("\nvalue : %s\n", cur->value);
		printf("type: %u\n", cur->type);
		cur = cur->next;
	}
	
	// while(split[i])
	// {
	// 	printf("s%d %s\n", i, split[i]);
	// 	i++;
	// }
	// i = 0;
	// while(split[i])
	// {
	// 	creat_token(&head, split[i], get_type(split[i]));
	// 	i++;
	// }
}

void ft_minishell_loop(void)
{
	t_data *data;
	
	data = ft_calloc(sizeof(t_data),1);
    while (1)
	{
		if(data == NULL)
			data = ft_calloc(sizeof(t_data),1);
        data->input = readline("minishell$ ");
        if (!data->input)
            break;
        if (strcmp(data->input, "exit") == 0) 
		{
            printf("exit\n");
            free(data); 
			break;
        }
        if (*data->input)
            add_history(data->input);
		ft_init_data(&data);
		lexer(&data);
		// tokenizing();
	    free(data);
		data = NULL;
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