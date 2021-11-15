#include "../libft.h"

int ft_strncmp(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        str1++; 
        str2++;
        if (*str1 > *str2) 
        {
            return 1;
        }
        else if (*str1 < *str2)
        {
            return -1;
        }
    }
    return 0;
}