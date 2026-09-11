#include <unistd.h>

int     ft_atoi(const char *str)
{
    int     sign;
    int     result;

    sign = 1;
    result = 0;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-');
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + *str - '0';
        str++;
    }
    return (result * sign);
}

/*
What real atoi handles (per the man page): 
- Skips leading whitespace characters (spaces, tabs, newlines, etc.)
- Optionally reads a single + or - sign
- Reads as many consecutive digits as it can
- Stops at the first non-digit character (ignores anything after)
- If no valid conversion could be performed, returns 0


*/