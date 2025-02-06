/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2025/02/06 05:24:46 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parsing(t_minishell *ms)
{
	split_input(ms);
	buil_cmd_list(ms);
	// print_cmd(ms);
}

void	ft_minishell_loop(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	while (1)
	{
		free_data(ms);
		init_data(ms);
		d->envp = ms->envp;
		d->input = readline("mini-3.1$ ");
		// if(ft_strcmp (d->input, "exit") == 0)
		// 	break ;
		if (!d->input)
			break ;
		if (d->input)
			add_history(d->input);
		parsing(ms);
		execution(ms);
	}
}

// void	print_cmd(t_minishell *ms)
// {
// 	t_token		*tok_curr;
// 	t_cmd		*cmd_curr;
// 	t_data		*d;
	
// 	int			i;
// 	int			j;

// 	d = &ms->data;
// 	cmd_curr = d->cmd_list;
// 	tok_curr = d->tok_list;
// 	printf("\n");
// 	while (tok_curr)
// 	{
// 		printf("%s ", tok_curr->value);
// 		tok_curr = tok_curr->next;
// 	}
// 	printf("\n");
// 	printf("\n\n***** list.token **** \n\n");
// 	j = 0;
// 	while (cmd_curr)
// 	{
// 		i = 0;
// 		printf("t_cmd *node [%d] = {\n", cmd_curr->id);
// 		if (cmd_curr->argv)
// 		{
// 			printf("    .argv = {");
// 			while (cmd_curr->argv[i])
// 			{
// 				printf(" \"%s\"", cmd_curr->argv[i]);
// 				if (cmd_curr->argv[i + 1])
// 					printf(", ");
// 				else
// 					printf(" },\n");
// 				i++;
// 			}
// 		}
// 		else
// 			printf("    .argv = { NULL },\n");
// 		printf("    .path = \"%s\",\n", cmd_curr->path);
// 		const char	*redir_str[] = {"NOT", "SINGLE_IN", "SINGLE_OUT", "DOUBLE_IN",
// 		"DOUBLE_OUT"};
// 		printf("    .rdir = %s,\n", redir_str[cmd_curr->rdir]);
// 		printf("    .fd_rdir = \"%s\",\n", cmd_curr->fd_rdir);
// 		printf("    .next = %s\n", cmd_curr->next ? "Non-null" : "NULL");
// 		printf("\n");
// 		cmd_curr = cmd_curr->next;
// 		j++;
// 	}
// }
