#include <unistd.h>

int     is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int     main(int argc, char **argv)
{
    int len;
    int end;
    int start;

    if (argc != 2)
        write(1, "\n", 1);
    else
    {
        len = 0;
        while (argv[1][len])
            len++;
        end = len - 1;
        while (end >= 0 && is_space(argv[1][end]))
            end--;
        if (end < 0)
            write(1, "\n", 1);
        else
        {
            start = end;
            while (start > 0 && !is_space(argv[1][start - 1]))
                start--;
            write(1, &argv[1][start], end - start + 1);
            write(1, "\n", 1);
        }
    }
    return (0);
}