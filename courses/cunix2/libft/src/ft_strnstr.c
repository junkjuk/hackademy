#include "../libft.h"

char *ft_strnstr(const char *s, const char *find, size_t slen)
{
    const char *start = s;
    if(*find == '\0')
    {
        return (char *)s;
    }

    while (*s != '\0' && (((unsigned int)(s - start)) <= slen))
    {
        if(*s == *find) 
        {
            const char *newS = s;
            const char *newFind = find;
            while(((unsigned int)(s -start)) <= slen)
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