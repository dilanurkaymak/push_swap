#include "push_swap.h"

void    sa(t_list **stack)
{
    t_list *first;
    t_list *second;
    t_data *tmp;

    if(!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    second = first->next;
    tmp = first->content;
    first->content = seond->content;
    second->content = tmp;
    write(1,"sa\n", 3);
}

void    pb(t_list **a, t_list **b)
{
    t_list *node;

    if(!a || *a)
        return ;
    node = *a;
    *a = node->next;
    ft_lstadd_front(b, node);
    write(1,"pb\n", 3);
}

void pa(t_list **a, t_list **b)
{
    t_list *node;

    if(!b || !*b)
        return ;
    node = *b;
    *b = node->next;
    ft_lstadd_front(a, node);
    write(1, "pa\n", 3);
}

void ra(t_list **stack)
{
    t_list *first;
    t_list *last;

    if(!stack || !*stack || !(*stack)->next)
        return ;
    first = *stack;
    *stack = first->next;
    first->next =  NULL;
    last = ftlstlast(*stack);
    last->next = first;
    write(1, "ra\n", 3);
}

void rra(t_list **stack)
{
    t_list *prev;
    t_list *last;

    if(!stack || !*stack || !(*stack)->next)
        return ;
    last = *stack;
    prev = NULL;
    while(last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
    write(1, "rra\n", 4);
}
