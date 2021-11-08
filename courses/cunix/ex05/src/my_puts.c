#include <unistd.h>

int my_strlen(const char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        str++;
        len++;
    }
    return len;
}

int my_puts(const char *s)
{

    int result = write(STDOUT_FILENO, s, my_strlen(s));
    char emptyStr[] = "\n";
    write(STDOUT_FILENO, emptyStr, sizeof(emptyStr) - 1);
    
    return result;
}