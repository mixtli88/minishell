#include "libft.h"

char    *ft_strtok(char *str, int delim)
{
    static char *last;
    char        *tmp;
    int         i;

    i = 0;
    if (str)
        last = str;
    if (!last)
        return (NULL);
    while (last[i])
    {
        if (last[i] == delim)
        {
            last[i++] = '\0';
            tmp = last;
            last += i;
            return (tmp);
        }
        i++;
    }
    tmp = last;
    last = NULL;
    return (tmp);
}
