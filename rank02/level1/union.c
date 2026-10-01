#include <unistd.h>

int ft_strlen(char *s)
{
    int len;

    len = 0;
    while (s[len])
        len++;
    return (len);
}

int has(char *s, char c, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}
// it checks only the first n characters
// passing i as n means: only look at what came before the current position
// passing len means: look at the whole string

int main(int argc, char **argv)
{
    int i;
    int len;

    if (argc == 3)
    {
        len = ft_strlen(argv[1]);
        i = 0;
    
        while (argv[1][i])
        {
            if (!has(argv[1], argv[1][i], i))
                write(1, &argv[1][i], 1);
            i++;
        }
        i = 0;
        while (argv[2][i])
        {
            if (!has(argv[1], argv[2][i], len) && !has(argv[2], argv[2][i], i))
                write(1, &argv[2][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}


/*
the logic:
- For each character of argv[1], print it unless it 
already appeared earlier in argv[1]
- For each character of argv[2], print it unless
it appears anywhere in argv[1] or earlier in argv[2]

Both checks are the same operation: 
does this character appear in the first n characters of that string?
So one helper function covers them. 
*/