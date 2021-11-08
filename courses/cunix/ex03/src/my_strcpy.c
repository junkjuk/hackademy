#include<stdio.h>

char *my_strcpy(char *dest, const char *src)
{
    char *asd = dest;

    while (*src != '\0')
    {    
        *dest = *src;
        
        printf(" %c --- %c\n", *src, *dest);
        src++;
        if (*src != '\0')
        {
            dest++;
        }
        printf(" %p --- %p\n", src, dest);
        
    }

    
   
    return asd;
}

int main() 
{
    char a[40];
    
    printf(" %d --- %d \n", my_strcpy(a, "123456789"), &a);
    printf("%s \n", a);
    return 0;
}