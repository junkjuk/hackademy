#include "../include/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "tools/ft_strlen.c"
#include "tools/my_atoi.c"
#include "tools/my_itoa.c"
#include <limits.h>

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
                long long numb = va_arg(args, int);
                int lenght = 0;

                if (spaceFlag == 1 && numb >= 0)
                {
                    lenght++;
                    write(STDOUT_FILENO, " ", 1);
                }

                if (zeroFlag == 0)
                {
                    if (plusFlag == 1)
                    {
                        if (numb < 0)
                        {
                            lenght++;
                        }
                        else if (plusFlag == 1 && numb > 0)
                        {

                            lenght++;
                        }
                    }

                    char *str = my_itoa(numb);
                    output = str;
                    lenght += ft_strlen(output);
                    while (width - lenght > 0)
                    {
                        write(STDOUT_FILENO, " ", 1);
                        width--;
                    }
                    if (plusFlag == 1 && numb >= 0)
                    {
                        write(STDOUT_FILENO, "+", 1);
                    }
                }
                else if (zeroFlag == 1)
                {
                    if (numb < 0)
                    {
                        write(STDOUT_FILENO, "-", 1);
                        numb *= -1;
                        lenght++;
                    }
                    else if (plusFlag == 1 && numb >= 0)
                    {
                        write(STDOUT_FILENO, "+", 1);
                        lenght++;
                    }
                    char *str = my_itoa(numb);
                    output = str;
                    lenght += ft_strlen(output);
                    while (width - lenght > 0)
                    {
                        write(STDOUT_FILENO, "0", 1);
                        width--;
                    }
                }
            }
            else if (format[i] == 'c')
            {
                output = (char *)malloc(2 * sizeof(char));
                output[0] = va_arg(args, int);
                output[1] = '\0';
                int lenght = ft_strlen(output);
                while (width - lenght > 0)
                {
                    write(STDOUT_FILENO, " ", 1);
                    width--;
                }
            }
            else if (format[i] == 's')
            {
                output = va_arg(args, char *);
                if (output == NULL)
                {
                    output = "(null)";
                }
                int lenght = ft_strlen(output);

                if (zeroFlag == 0)
                {
                    while (width - lenght > 0)
                    {
                        write(STDOUT_FILENO, " ", 1);
                        width--;
                    }
                }
                else if (zeroFlag == 1)
                {
                    while (width - lenght > 0)
                    {
                        write(STDOUT_FILENO, "0", 1);
                        width--;
                    }
                }
            }
            else if (format[i] == '%')
            {
                output = "%";
            }

            write(STDOUT_FILENO, output, ft_strlen(output));
        }
    }
}

// int main()
// {

//     printf("%i\n", INT_MIN);
//     ft_printf("%d", -2147483648);
// }