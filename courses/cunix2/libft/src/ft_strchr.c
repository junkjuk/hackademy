#include "../libft.h"

char *ft_strchr(const char *str, int ch)
{
    while (*str != '\0')
    {
        if (*str == (char)ch)
        {
            return (char *)str;
        }
        str++;
    }

    return 0;
}