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
    else if (a > b && b > c)
    {
        sa(stack);
        rra(stack);
    }
    else if(a >b && b < c && a > c)
        ra(stack);
    else if(a < b && b > c && a < c)
    {
        sa(stack);
        ra(stack);
    }
    else if(a < b && b > c && a > c)
        rra(stack);
}

void    sort_small(t_list **stack_a, t_list *stack_b)
{
    int size = ft_lstsize(*stack_a);

    if(size == 2)
        sort_two(stack_a);
    else if(size == 3)
        sort_three(stack_a);
    else
    {
        while(ft_lstsize(*stack_a) > 3)
        {
            t_list *cur = *stack_a;
            t_data *data = (t_data *)cur->content;
            t_data *min_data = data;
            t_list *min_code = cur;


            while (cur)
            {
                t_data *tmp = (t_daata *)cur->content;
                if(tmp->value < min__data->value)
                {
                    min_data = tmp;
                    min_node = cur;
                }
                cur = cur->next;
            }
            //en küçük node başa gelicek ve pb
            while (*stack_a != min_node)
                ra(stack_a);
            pb(stack_a, stack_b);
        }
        sort_three(stack_a);
        while (*stack_b)
            pa(stack_a, stack_b);
    }
}
