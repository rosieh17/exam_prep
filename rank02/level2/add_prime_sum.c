#include <unistd.h>

int ft_atoi(char *str)
{
    int sign = 1;
    int result = 0;

    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = *str - '0' + result * 10;
        str++;
    }
    return (result * sign);
}

int is_prime(int n)
{
    int i;

    if (n < 2)
        return (0);
    i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int num;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return;
    }

    num = ft_atoi(argv[1]);
    if (num <= 0)
    {
        write(1, "\n", 1);
        return;
    }
    else
    {
        if 
    }
}