#include <unistd.h>

void    putstr(char *str)
{
    int i = 0;

    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}






int     main(void)
{
    char    *str;
   
    str = "Hello, world";
    putstr(str);
    write(1, "\n", 1);
    return (0);
}