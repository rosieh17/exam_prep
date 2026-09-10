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
                c = (argv[1][i] - 'a' + 1) % 26 + 'a';
            else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                c = (argv[1][i] - 'A' + 1) % 26 + 'A';
            else
                c = argv[1][i];
            write(1, &c, 1);
            i++;
        }
    }
    write(1, "\n", 1);
}