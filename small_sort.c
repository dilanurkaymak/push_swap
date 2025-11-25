#include "push_swap.h"

static int  get_min_pos(t_list *stk)
{
    int min_val;
    int min_pos;
    int i;

    if(!stk)
        return (-1);

    min_val = ((t_data *)stk->content)->value;
    min_pos = 0;
    i = 0;

    while (stk)
    {
        t_data *data = (t_data *)stk->content;
        if(data->value < min_val)
        {
            min_val = data->value;
            min_pos = i;
        }
        stk = stk->next;
        i++;
    }
    return (min_pos);
}

static void sort_two(t_list **stk)
{
    t_data  *first = (t_data *)(*stk)->content;
    t_data  *second = (t_data *)(*stk)->next->content;
    if(first->value > second->value)
        sa(stk);
}

static void sort_three(t_list **stk)
{
    int first;
    int second;
    int third;

    first = ((t_data *)(*stk)->content)->value;
    second = ((t_data *)(*stk)->next->content)->value;
    third = ((t_data *)(*stk)->next->next->content)->value;
    if (first > second && second < third && first < third)
        sa(stk);
    else if (first > second && second > third)
    {
        sa(stk);
        rra(stk);
    }
    else if(first >second && second < third && first > third)
        ra(stk);
    else if(first < second && second > third && first < third)
    {
        sa(stk);
        ra(stk);
    }
    else if(first < second && second > third && first > third)
        rra(stk);
}

void    sort_small(t_list **stk_a, t_list **stk_b)
{
    int size;
    int min_pos;

    size = ft_lstsize(*stk_a);
    if(size <= 1)
        return ;
    if(size == 2)
        sort_two(stk_a);
    else if(size == 3)
        sort_three(stk_a);
    else
    {
        while(ft_lstsize(*stk_a) > 3)
        {
            min_pos = get_min_pos(*stk_a);
            size = ft_lstsize(*stk_a);
            
            if (min_pos > size / 2)
            {
                int moves = size - min_pos;
                while(moves--)
                    rra(stk_a);
            }
            else
            {
                int moves = min_pos;
                while(moves--)
                    ra(stk_a);
            }

            pb(stk_a, stk_b);
        }
        sort_three(stk_a);
        while (*stk_b)
            pa(stk_a, stk_b);
    }
}
