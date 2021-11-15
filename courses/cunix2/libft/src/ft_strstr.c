#include "../libft.h"

char *ft_strstr(const char *s, const char *find)
{
    if(*find == '\0')
    {
        return (char *)s;
    }

    while (*s != '\0')
    {
        if(*s == *find) 
        {
            const char *newS = s;
            const char *newFind = find;
            while(1)
            {
                if(*newFind == '\0')
                {
                    return (char *)s;
                }

                if(*newFind != *newS)
                {
                    break;
                }

                newS++;
                newFind++;
            }
        }   
        s++;
    }


    return NULL;
}