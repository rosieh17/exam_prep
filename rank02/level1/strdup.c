#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int     len;
    int     i;
    char    *dup;

    len = 0;
    while (src[len])
        len++;
    dup = malloc(sizeof(char) * (len + 1));
    if (dup == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}
