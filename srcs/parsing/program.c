/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mike <mike@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:15:33 by fwu               #+#    #+#             */
/*   Updated: 2025/04/02 06:43:54 by mike             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int g_signal_status = 0;

void	parsing(t_minishell *ms)
{
	if(split_input(ms))
		buil_cmd_list(ms);
	// print_cmd(ms);
}

void	 ft_minishell_loop(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	set_sig_local(ms);
	while (1)
	{
		init_data(ms);
		d->input = readline("\033[1;32mmini-3.1$ \033[0m");
		if (g_signal_status == 2)
			d->flag = -1;
		if (!d->input)
			break ;		
		if (d->input[0] != '\0' && d->flag != -1)
			add_history(d->input);
		if (d->flag != -1)
			parsing(ms);
		if(d->cmd_list)
			execution(ms);
		free_data(ms);
		signal(SIGINT, handle_signal);
		signal(SIGQUIT, handle_signal);
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
// 	tok_curr = d->token_list;
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
// 		// printf("    .rdir = %s,\n", redir_str[cmd_curr->rdir->type]);
// 		// printf("    .fd_rdir = \"%s\",\n", cmd_curr->rdir->fd_rdir);
// 		while (cmd_curr->rdir)
// 		{
// 			printf("    .rdir =\"%s\" - \"%s\"", redir_str[cmd_curr->rdir->type], cmd_curr->rdir->fd_rdir);
// 			if (cmd_curr->rdir->next)
// 				printf(", ");
// 			else
// 				printf(" },\n");
// 			cmd_curr->rdir = cmd_curr->rdir->next;
// 		}
// 		printf("    .next = %s\n", cmd_curr->next ? "Non-null" : "NULL");
// 		printf("\n");
// 		cmd_curr = cmd_curr->next;
// 		j++;
// 	}
// }
