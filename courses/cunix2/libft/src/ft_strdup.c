#include "../libft.h"

char *ft_srtdup(char *dest, const char *src)
{
    char *asd = dest;

    while (*src != '\0')
    {    
        *dest = *src;
        src++;
        if (*src != '\0')
        {
            dest++;
        }       
    }

    
   
    return asd;
}