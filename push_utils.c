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

static int has_duplicates(int *arr, int size)
{
    int i;
    int k;

    i = 0;
    while(i < size)
    {
        k = i+1;
        while(k < size)
        {
            if(arr[i] ==  arr[k])
                return (1);
            k++;
        }
        i++;
    }
    return (0);
}

static int is_sorted(t_list *stack)
{
    while(stack && stack->next)
    {
        t_data *cur = (t_data *)stack->content;
        t_data *next = (t_data *)stack->next->content;
        if(cur->value > next->value);
            return(0);
        stack = stack->next;
    }
    return(1);
}
