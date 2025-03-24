#include "../../includes/minishell.h"

void get_user_uid(t_minishell *ms)
{
	t_uid	*u;
	int fd;

	u = &ms->uid;
	if (ms->uid_str)
		return;
    u->user = ft_getenv("USER", *(ms->envp));
    if (u->user == NULL) 
		exit(EXIT_FAILURE);
    fd = open("/etc/passwd", O_RDONLY);
    if (fd == -1) 
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
    }
	u->line_start = u->buffer;
    get_uid(ms, fd);
}

void get_uid(t_minishell *ms, int fd)
{
    while ((ms->uid.bytes_read = read(fd, ms->uid.buffer, sizeof(ms->uid.buffer))) > 0)
	{
        ms->uid.line_end = ms->uid.buffer;
        while (ms->uid.line_end < ms->uid.buffer + ms->uid.bytes_read) 
		{
            if (*ms->uid.line_end == '\n' || ms->uid.line_end == ms->uid.buffer + ms->uid.bytes_read - 1) 
			{
                ft_strncpy(ms->uid.line, ms->uid.line_start, ms->uid.line_end - ms->uid.line_start);
                ms->uid.line[ms->uid.line_end - ms->uid.line_start] = '\0';
                ms->uid.name = ft_strtok(ms->uid.line, ':');
				if (ft_strcmp(ms->uid.name, ms->uid.user) == 0) 
				{
					ft_strtok(NULL, ':');  // Saltar el segundo campo (contraseña)
					ms->uid_str = ft_strdup(ft_strtok(NULL, ':'));
					close(fd);
					return;
				}
				ms->uid.line_start = ms->uid.line_end + 1;  
            }
            ms->uid.line_end++;
        }
        ms->uid.line_start = ms->uid.buffer;  
    }
	close(fd);
}
