/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabril <mabril@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:50:37 by mabril            #+#    #+#             */
/*   Updated: 2025/01/23 23:16:37 by mabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tok_is_cmd(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	d->tok_tem = d->token_cur;
	if (!d->cur_cmd)
		create_cmd(ms);
	else
		d->cur_cmd->argv[d->i++] = ft_strdup(d->token_cur->value);
}

void	tok_is_pipe(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (!d->token_cur->next || !d->cur_cmd)
		error_syntax(ms);
	else if (d->token_cur->next->type != CMD)
		error_syntax(ms);
	else
	{
		d->cur_cmd = NULL;
		d->tok_tem = NULL;
	}
}

void	tok_is_redi(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (!d->token_cur->next || d->token_cur->next->type != CMD)
		error_syntax(ms);
	if (!d->cur_cmd)
		create_cmd(ms);
	else
		char_is_rdir(ms);
}

void	create_cmd(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	d->tok_tem = d->token_cur;
	d->cur_cmd = creat_nod(ms);
	if (d->token_cur->type == REDIR)
		char_is_rdir(ms);
	d->count += 1;
	d->arg_c = 1;
	d->i = 0;
	d->cur_cmd->id = d->count;
	free(d->full_path);
	d->full_path = NULL;
	d->tok_tem = d->token_cur;
	while (d->tok_tem->next && d->tok_tem->next->type == CMD)
	{
		d->arg_c++;
		d->tok_tem = d->tok_tem->next;
	}
	if (!d->cur_cmd->argv)
		d->cur_cmd->argv = (char **)malloc(sizeof(char *) * (d->arg_c + 1));
	d->cur_cmd->argv[d->arg_c] = NULL;
	d->cur_cmd->argv[d->i++] = ft_strdup(d->token_cur->value);
}

void	char_is_rdir(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if (!d->token_cur->next || d->token_cur->next->type != CMD)
		error_syntax(ms);
	if (ft_strncmp(d->token_cur->value, "<", 1) == 0)
		d->cur_cmd->rdir = SINGLE_IN;
	else if (ft_strncmp(d->token_cur->value, ">", 1) == 0)
		d->cur_cmd->rdir = SINGLE_OUT;
	else if (ft_strncmp(d->token_cur->value, "<<", 2) == 0)
		d->cur_cmd->rdir = DOUBLE_IN;
	else if (ft_strncmp(d->token_cur->value, ">>", 2) == 0)
		d->cur_cmd->rdir = DOUBLE_OUT;
	d->cur_cmd->fd_rdir = ft_strdup(d->token_cur->next->value);
	d->token_cur = d->token_cur->next;
	d->token_cur = d->token_cur->next;
}

// void	tok_is_logic(t_minishell *ms)
// {
// 	t_data	*d;

// 	d = &ms->data;
// 	if (!d->token_cur->next)
// 		error_syntax(ms);
// 	else if (d->token_cur->next->type != CMD)
// 		error_syntax(ms);
// 	if (!d->cur_cmd)
// 		free_data(ms);
// 	else
// 		d->cur_cmd = NULL;
// }