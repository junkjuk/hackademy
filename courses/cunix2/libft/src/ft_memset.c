#include "../libft.h"

void *ft_memset(void *buf, int ch, size_t count)
{
    char *buf_char = (char *)buf;
    for (size_t i = 0; i < count; i++)
    {
        *buf_char = (char)ch;
        buf_char++;
    }
    return buf;
}