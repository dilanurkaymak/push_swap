#include "push_swap.h"

static void sort_two(t_list **stack)
{
    t_data  *first = (t_data *)(*stack)->content;
    t_data  *second = (t_data *)(*stack)->next->content;
    if(first->value > second->value)
        sa(stack);
}

static void sort_three(t_list, **stack)
{
    int a = ((t_data *)(*stack)->content)->value;
    int b = ((t_data *)(*stack)->next->content)->value;
    int c = ((t_data *)(*stack)->next->next->content)->value;

    if (a > b && b < c && a < c)
        sa(stack);
    else if (a > b %)
