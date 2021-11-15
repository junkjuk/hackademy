#include "../libft.h"
#include "stdio.h"

int getElementsN(const char *s, char c)
{
    int l = 0;
    while(*s != '\0')
    {
        if(*s != c)
        {
            s++;
            if(*s == c || *s  == '\0')
            {
                l++;
            }
            continue;
        }
        s++;
    }

    return l;
}

int getAllElementLength(const char *s, char c)
{
    int l = 0;
    while(*s != '\0')
    {
        if(*s != c)
        {
            l++;
        }
        s++;
    }

    return l;
}

int getElementLenght(const char *s, char c)
{
    int i = 0;
    while (*s == c && *s != '\0')
    {
        s++;
    }
    while (*s != c && *s != '\0')
    {
        s++;
        i++;
    }
    return i;
}

char *getElement(const char *s, char c)
{
    const char *end = s;
    while (*(end + 1) != c && *(end +1) != '\0')
    {
        end++;
    }

    char *element = malloc(sizeof(char) * (end - s + 2));
    char *pElement = element;

    while(s <= end)
    {
        *pElement = *s;
        s++;
        pElement++;
    }
    pElement = '\0';
    return element;
}

char **ft_strsplit(const char *s,char c)
{
    int countElements = getElementsN(s, c);

    if(countElements == 0)
    {
        char **emptyArray = malloc(sizeof(char *));
        *emptyArray = NULL;
        return emptyArray;
    }

    char **elements = malloc(sizeof(char *) * (countElements + 1));
    char **startElements = elements;

    while (*s != '\0')
    {
        while (*s == c)
        {
            s++;
        }

        *elements = getElement(s, c);
        elements++;
        while (*s != c && *s != '\0')
        {
            s++;
        }
    }
    *elements = NULL;
    return startElements;
}