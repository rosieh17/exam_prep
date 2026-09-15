#include <unistd.h>

int main(int argc, char **argv)
{
    int     i;
    int     j;
    int     in_second;
    int     seen_before;

    if (argc == 3)
    {
        i = 0;
        while (argv[1][i])
        {
            j = 0;
            in_second = 0;
            while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                    in_second = 1;
                j++;
            }
            j = 0;
            seen_before = 0;
            while (j < i)
            {
                if (argv[1][i] == argv[1][j])
                    seen_before = 1;
                j++;
            }
            if (in_second && !seen_before)
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}