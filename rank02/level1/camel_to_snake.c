#include <unistd.h>

int main(int argc, char **argv)
{
    int     i;
    char    c;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
            {
                write(1, "_", 1);
                c = argv[1][i] + ('a' - 'A');
                write(1, &c, 1);
            }
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

/*
This one follows the same pattern as your earlier exercises:
walk the string, transform each character, write it out.

The core logic:
for each character:
- if it's uppercase ('A'–'Z') → write an '_', then write the lowercase version of that letter.
- otherwise (already lowercase, or any other character) → write it unchanged.
*/