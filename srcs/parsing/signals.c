#include "../../includes/minishell.h"

void handle_signal(int sig)
{	
	(void)sig;
	int fd[2];
	
	rl_on_new_line();
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return;
	}
	write(fd[1], "  \n", 3);  
	close(fd[1]);           
	dup2(fd[0], STDIN_FILENO);	
	g_signal_status = 2;	
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
		if (signal(SIGINT, handle_signal) == SIG_ERR)
			perror("signal SIGINT");
	}
	sa.sa_handler = SIG_IGN;
    if (sigaction(SIGQUIT, &sa, NULL) == -1)
        perror("sigaction SIGQUIT");
}
