#include <unistd.h>

int     ft_strcmp(char *s1, char *s2)
{
    int     i;

    i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

/*
strcmp
compares two strings byte by byte, and returns
- 0, if the strings are equal
- a negative value, if the first differing byte in s1 is smaller
- a positive value, if the first differing byte in s1 is larger
*/