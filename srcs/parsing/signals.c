#include "../../includes/minishell.h"

void handle_signal(int sig)
{
	(void)sig;
	int fd[2];
	
	rl_on_new_line();
	rl_redisplay();
	if(g_signal_status == 1)
	{
		if (pipe(fd) == -1)
		{
			perror("pipe");
			return;
		}
		write(fd[1], "   \n", 4);  
		close(fd[1]);           
		dup2(fd[0], STDIN_FILENO);	
        g_signal_status = 2;
	}
	else
	{		
		printf("   \n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();	
	}
	
}
void handle_signal_son(int sig)
{
	(void)sig;
	if(sig == SIGQUIT)
		ft_putstr_fd("Quit (core dumped)\n", STDOUT_FILENO); // Imprime un salto de línea
	else if(sig == SIGINT)
		ft_putstr_fd("\n", STDOUT_FILENO); // Imprime un salto de línea
}

void set_sig_local(t_minishell *ms)
{
	struct sigaction sa;
	
	ms->data.g_stdin = dup(STDIN_FILENO);
	if (ms->data.g_stdin == -1)
	{
		perror("dup");
		exit(EXIT_FAILURE);
	}	
	if(SIGINT)
	{
		if(ms->data.flag_readline == 1)
		{
			g_signal_status = 1;
			ms->data.flag_readline = 0;
		}
		ms->status = 130;
		if (signal(SIGINT, handle_signal) == SIG_ERR)
			perror("signal SIGINT");
	}
	sa.sa_handler = SIG_IGN;
    if (sigaction(SIGQUIT, &sa, NULL) == -1)
        perror("sigaction SIGQUIT");
}
