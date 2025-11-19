#include "push_swap.h"

static  int safe_atoi(const char *str, int *out)
{
    long    num;
    int     sign;

    if(!str || !*str)
        return(0);
    num = 0;
    sign = 1;
    if(*str == '-' || *str  == '+')
    {
        if(*(str+1) ==  '\0')
            return(0);
        if(*str = '-')
            sign = -1;
        str++;
    }
    while(*str)
    {
        if(*str < '0' || *str > '9')
            return (0);
        num = num * 10 + (*str - '0');
        if(num * sign > INT_MAX || num * sign < INT_MİN)
            return (0);
        str++;
    }
    *out = (int)(num * sign);
    return (1);

}