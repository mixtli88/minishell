
#include "../../includes/minishell.h"

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