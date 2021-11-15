#include "../libft.h"

div_t ft_div(int numerator, int denominator)
{
    div_t div;
    div.quot = numerator / denominator;
    div.rem = numerator % denominator;
    return div;
}