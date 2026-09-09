#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    char c;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
                c = 'a' + (argv[1][i] - 'a' + 13) % 26;
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                c = 'A' + (argv[1][i] - 'A' + 13) % 26;
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
"13 letters ahead" means you need to wrap around the alphabet

c = 'a' + (argv[1][i] - 'a' + 13) % 26;   // lowercase
c = 'A' + (argv[1][i] - 'A' + 13) % 26;   // uppercase

*/