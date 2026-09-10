#include <unistd.h>

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

int main(int argc, char **argv)
{
    int i = 0;

    if (argc == 4 && ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
    {
        while (argv[1][i])
        {
            if (argv[1][i] == argv[2][0])
                write(1, argv[3], 1);
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}


/*
write(1, argv[3], 1);

why this syntax works: 
argv[3] 
type: char *
It is a pointer, the address of the first character of that argument string


argv[3][0]
type: char
It is a single character, the value stored at that first position



both works: 
write(1, argv[3], 1);
write(1, &argv[3][0], 1);
because write()'s second parameter needs an address to read from, not a character value. 
argv[3]  is already a char *, an address, so it can go straight into write() without any &

argv[3][0] is a char (a value, not an address), so you need &argv[3][0] to get its address
*/