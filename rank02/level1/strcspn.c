#include <unistd.h>

size_t  ft_strcspn(const char *s, const char *reject)
{
    size_t  i;
    size_t  j;

    i = 0;
    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

/*
return type:
size_t is an unsigned integer type (used for sizes/counts in C)
i naturally fits this since it can only be 0 or positive, 
matching the real strcspn prototype exactly.
*/