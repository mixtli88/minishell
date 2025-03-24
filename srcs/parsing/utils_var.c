#include "../../includes/minishell.h"

void expand_var_without_quotes(t_minishell *ms)
{
	t_data	*d;
	char **words;
	int		i;
	int		j;

	i = 0;
	d = &ms->data;
	words = ft_split(d->var, ' ');
	while(words[i])
	{
		j = 0;
		while(words[i][j]) 
			d->buff[d->buf_idx++] = words[i][j++];
		d->buff[d->buf_idx] = '\0';
		creat_token(ms);
		d->token_cur->type = CMD;
		i++;
	}
	free_table(words);
}

void expand_var_with_quotes(t_minishell *ms)
{
	t_data	*d;
	int		i;

	i = 0;
	d = &ms->data;
	while (d->var[i])
		d->buff[d->buf_idx++] = d->var[i++];
	if(d->var)
		free(d->var);
	d->var = NULL;
}

void  if_var_alpnum(t_minishell *ms)
{
	t_data    *d;
	int		j;

	j = 0;
	d= &ms->data;
	d->i++;
	while (ft_isalnum(d->input[d->i]) || d->input[d->i] == '_')
		d->var_buf[j++] = d->input[d->i++];
	d->var_buf[j] = '\0';
	if(ft_strcmp(d->var_buf, "UID") == 0)
		d->var = ft_strdup(ms->uid_str);
	else
		d->var = ft_getenv(d->var_buf, *(ms->envp));
	d->var_buf[0] = '\0';
	if (!d->var)
		return ;
	if(d->in_quotes || ft_strchr(d->var, ' ') == 0)
		expand_var_with_quotes(ms);
	else
		expand_var_without_quotes(ms);
}
