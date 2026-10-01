#include <stdlib.h>

int     is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int     count_words(char *str)
{
    int     i;
    int     count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        if (str[i] && !is_space(str[i]))
            count++;
        while (str[i] && !is_space(str[i]))
            i++;
    }
    return (count);
}

char    *new_word(char *str, int start, int len)
{
    char    *word;
    int     i;

    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    i = 0;
    while (i < len)
    {
        word[i] = str[start + i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

char    **ft_split(char *str)
{
    char    **result;
    int     words;
    int     i;
    int     w;
    int     start;

    words = count_words(str);
    result = malloc(sizeof(char *) * (words + 1));
    if (!result)
        return (NULL);
    i = 0;
    w = 0;
    while (w < words)
    {
        while (is_space(str[i]))
            i++;
        start = i;
        while (str[i] && !is_space(str[i]))
            i++;
        result[w] = new_word(str, start, i - start);
        w++;
    }
    result[w] = NULL;
    return (result);
}

/*
start remembers where the word began; i advances until it hits whitespace 
or the end of the string. i - start is then exactly the word's length, which 
new_word uses to know how many characters to copy.
*/