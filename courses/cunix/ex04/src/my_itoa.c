#include<stdlib.h>

char *my_itoa(int nmb)
{

    char *result = malloc(sizeof(char) * 32);

    if (nmb == 0)
    {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    
    int r = 0;
    int dublicateN = nmb;
    while (dublicateN != 0)
    {
        r++;
        dublicateN /= 10;
    }

    if (nmb < 0)
    {
        result[r + 1] = '\0';
        result[0] = '-';
        nmb *= -1;
        for (int i = r; i > 0; i--)
        {
            result[i] = '0' + nmb % 10;
            nmb /= 10;
        }  
    } 
    else 
    {
        result[r] = '\0';
        for (int i = r - 1; i >= 0; i--)
        {
            result[i] = '0' + nmb % 10;
            nmb /= 10;
        }  
    }
    return result;
}
