#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc == 3)
    {
        i = 0;
        j = 0;
        while (argv[1][i] && argv[2][j])
        {
            if (argv[1][i] == argv[2][j])
                i++;
            j++;
        }
        if (argv[1][i] == '\0')
        {
            i = 0;
            while (argv[1][i])
            {
                write(1, &argv[1][i], 1);
                i++;
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}

/*
This is a subsequence check: the characters of the first string
must appear in the second string in the same order, but not necessarily
next to each other.

The logic:
use one index for each string:
- j walks through the second string from left to right, one character
at a time
- i walks how much of the first string you've matched so far
- whenever s2[j] equals the character you're waiting for (s1[i]), 
move i forward

If i reaches the end of the first string, every character was found
in order. If j runs out of the second string, the match failed. 

j always advances, i only on a match.
*/