#include "../libft.h"
#include "ft_strlen.c"

char *ft_strjoin(const char *s1, const char *s2)
{
    int size_s1 = ft_strlen(s1);
    int size_s2 = ft_strlen(s2);
    char *freshStr = malloc(size_s1 + size_s2 + 1);
    char *pFreshStr = freshStr;
    while (*s1 != '\0') 
    {
        *pFreshStr = *s1;
        pFreshStr++;
        s1++;
    }
    while (*s2 != '\0')
    {
        *pFreshStr = *s2;
        pFreshStr++;
        s2++;
    }
    *pFreshStr = '\0';
    return freshStr;
}