#include "push_swap.h"

int is_sorted(t_list *stk)
{
    while(stk && stk->next)
    {
        t_data *cur = (t_data *)stk->content;
        t_data *next = (t_data *)stk->next->content;
        if (cur->value > next->value)
            return (0);
        stk = stk->next;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_list  *stk_a;
    t_list  *stk_b;

    stk_a = NULL;
    stk_b = NULL;
    if (argc < 2)
        return (0);
    stk_a = parse_args(argc, argv);
    if (!stk_a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    if (!is_sorted(stk_a))
    {
        if(ft_lstsize(stk_a) <= 7)
            sort_small(&stk_a, &stk_a);
        else
        {
            set_rank(stk_a);
            radix_sort(&stk_a, &stk_b);
        }
    }
    free_stack(&stk_a);
    free_stack(&stk_b);
    return (0);

}