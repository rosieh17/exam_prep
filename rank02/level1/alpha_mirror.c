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
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
                c = 'z' - (argv[1][i] - 'a');
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                c = 'Z' - (argv[1][i] - 'A');
            else
                c = argv[1][i];
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}


/*
Notice the pairing: a(0)↔z(25), b(1)↔y(24), c(2)↔x(23), d(3)↔w(22)... 
In each pair, the two positions add up to 25. 
So if a letter is at position p, its mirror is at position 25 - p.

Build the formula:
1. Convert letter to 0–25 position: argv[1][i] - 'a'
2. Mirror it: 25 - (argv[1][i] - 'a')
3. Convert back to a letter: 'a' + (25 - (argv[1][i] - 'a'))

since 'a' + 25 = 'z'
this simplifies into 
c = 'z' - (argv[1][i] - 'a');   // lowercase
c = 'Z' - (argv[1][i] - 'A');   // uppercase

*/