#include "../include/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "tools/ft_strlen.c"
#include "tools/my_atoi.c"
#include "tools/my_itoa.c"

void ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int strLen = ft_strlen(format);
    int spaceFlag = 0;
    int plusFlag = 0;
    int minusFlag = 0;
    int zeroFlag = 0;
    int width = 0;

    for (int i = 0; i < strLen; i++)
    {
        while (i < strLen && format[i] != '%')
        {
            write(STDOUT_FILENO, &format[i], 1);
            i++;
        }

        if (format[i] == '%')
        {
            i++;

            while (format[i] == '0' || format[i] == '-' || format[i] == '+' || format[i] == ' ')
            {
                if (format[i] == '0')
                {
                    zeroFlag = 1;
                }
                else if (format[i] == '-')
                {
                    minusFlag = 1;
                }
                else if (format[i] == '+')
                {
                    plusFlag = 1;
                }
                else if (format[i] == ' ')
                {
                    spaceFlag = 1;
                }
                i++;
            }

            if (minusFlag == 1)
            {
                zeroFlag = 0;
            }

            if (plusFlag == 1)
            {
                spaceFlag = 0;
            }

            if (format[i] >= '1' && format[i] <= '9')
            {
                width = my_atoi(&format[i]);
                i++;
                while (format[i] >= '0' && format[i] <= '9')
                {
                    i++;
                }
            }

            char *output = NULL;

            if (format[i] == 'i' || format[i] == 'd')
            {
                char *str = my_itoa(va_arg(args, int));
                output = str;
                if (plusFlag == 1 && my_atoi(output) > 0)
                {
                    write(STDOUT_FILENO, "+", 1);
                }
            }
            else if (format[i] == 'c')
            {
                zeroFlag = 0;
                char str = va_arg(args, int);
                char *pStr = &str;
                int sLen = ft_strlen(pStr);

                if (width <= sLen)
                {
                    output = "c";
                }
                else
                {
                    char *newStr = (char *)malloc(sizeof(char) * (width + 1));
                    newStr[width] = '\0';

                    if (minusFlag == 1)
                    {
                        for (int j = sLen; j < width; j++)
                        {
                            newStr[i] = ' ';
                        }

                        for (int j = 0; j < sLen; j++)
                        {
                            newStr[i] = pStr[i];
                        }
                    }
                    else
                    {
                        int start = width - sLen;

                        for (int j = 0; j < start; j++)
                        {
                            newStr[i] = ' ';
                        }

                        for (int j = start; j < width; j++)
                        {
                            newStr[i] = pStr[j - start];
                        }
                    }
                    output = newStr;
                }
            }
            else if (format[i] == 's')
            {
                if (zeroFlag == 0)
                {
                    while (width != 0)
                    {
                        write(STDOUT_FILENO, " ", 1);
                        width--;
                    }
                }

                output = va_arg(args, char *);
            }
            else if (format[i] == '%')
            {
                output = "%";
            }
            // printf("%s   \n", output);

            write(STDOUT_FILENO, output, ft_strlen(output));
        }
    }
}

// int main()
// {

//     // printf("2 --- %s\n", ft_printf("qwer"));

//     ft_printf("qwer%d", 42);
// }