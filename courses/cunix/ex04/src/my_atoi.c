
int my_atoi(const char *nptr)
{
    int result = 0;

    if (*nptr == '-')
    {
        nptr++;
        while (*nptr >= '0' && *nptr <= '9')
        {
            result *= 10;
            result += *nptr - '0';
            nptr++;
        }
        result *= -1;
    } 
    else
    {
        while (*nptr >= '0' && *nptr <= '9')
        {
            result *= 10;
            result += *nptr - '0';
            nptr++;
        }
    }
    return result;
}