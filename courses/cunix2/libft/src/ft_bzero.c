#include "../libft.h"

void ft_bzero(void *s, size_t n)
{
    char *newChar = (char *)s;
    for (size_t i = 0; i < n; i++)
    {
        *(newChar + i) = '\0';
    }
}