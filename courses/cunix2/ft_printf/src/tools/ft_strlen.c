#include "../../include/ft_printf.h"

int ft_strlen(const char *str)
{
    int len = 0;
    while (*str!= '\0')
    {
        len++;
        str++;
    }
    return len;
}