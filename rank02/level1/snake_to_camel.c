#include <unistd.h>

int main(int argc, char **argv)
{
    int     i;
    int     upper;
    char    c;

    i = 0;
    upper = 0;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] == '_')
                upper = 1;
            else
            {
                c = argv[1][i];
                if (upper && c >= 'a' && c <= 'z')
                    c -= 'a' - 'A';
                write(1, &c, 1);
                upper = 0;
            }
            i++;
        }

    }
    write(1, "\n", 1);
    return (0);
}

/*
the logic is to walk through the string one character
at a time:
- if the character is '_', don't print it. Just remember 
that the next letter must be capitalized.
- Otherwise, print the character, converting it to uppercase
first if that reminder is set. Then clear the reminder. 

The reminder is a simple flag variable. 
*/