
#include "../../includes/minishell.h"

void handle_var_in_herdoc(t_minishell *ms)
{
	t_data	*d;

	d = &ms->data;
	if(d->count_quote == 0 && ((d->input[d->i + 1] == '\'')
		|| (d->input[d->i +1] == '\"')) 
		&& d->input[d->i - 1] != '$')
			d->i++;
	else
		d->buff[d->buf_idx++] = d->input[d->i++];
}

bool on_signal(t_minishell *ms)
{
    if (g_signal_status == 2 || !ms->data.new_inp)
    {
        if (!ms->data.new_inp)
            error_pipe(ms);
        ms->data.flag = -1;
        return(true);
    }
    return(false);
}