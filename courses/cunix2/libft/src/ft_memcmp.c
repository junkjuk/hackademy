#include "../libft.h"

int ft_memcmp(void *buf1, const void *buf2, size_t count)
{
    unsigned char *buf1_char = (unsigned char *)buf1;
    unsigned char *buf2_char = (unsigned char *)buf2;
    for (size_t i = 0; i < count; i++)
    {

        if(*buf1_char < *buf2_char)
        {
            return -1;
        }
        else if(*buf1_char > *buf2_char)
        {
            return 1;
        }
        buf1_char++;
        buf2_char++;
    }
    return 0;
}