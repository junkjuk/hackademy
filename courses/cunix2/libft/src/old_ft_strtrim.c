#include "../libft.h"
#include "ft_strlen.c"


int isEmpty(char s)
{
    return s == ' ' || s == '\t' || s == '\n';
}

const char *getStart(const char *s)
{
    while ( isEmpty(*s) && (*s == '\0'))
    {
        s++;
    }
    return s;
}
const char *getEndL(const char *s)
{
    while (*s != '\0')
    {
        s++;
    }
    return s - 1;
}


const char *getEnd(const char *s)
{
    const char *end = getEndL(s);

    while (s != end && isEmpty(*s))
    {
        end--;
    }
    return end;
}

char *ft_strtrim(const char *s)
{
    const char *start = getStart(s);
    const char  *end = getEnd(s);

    if( end < start )
    {
        char *returnedStr = malloc(1);
        *returnedStr = '\0';
        return returnedStr;
    }

    char *returnedStr = malloc(end - start + 2);
    char *pReturnedStr = returnedStr;

    while (start <= end)
    {
        *pReturnedStr = *start;
        start++;
        pReturnedStr++;
    }
    *pReturnedStr = '\0';

    return returnedStr;
}