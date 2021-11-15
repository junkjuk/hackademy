#include "../libft.h"

char *ft_strchr(const char *str, int ch)
{
    char *p;
    
    while (*str != '\0')
    {
        if (*str == (char)ch)
        {
            p = (char *)str;
        }
        str++;
    }
    return p;
}