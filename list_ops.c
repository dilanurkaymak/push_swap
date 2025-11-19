#include "push_swap.h"

t_list  *new_node(int value)
{
    t_data *data = malloc(sizeof(t_data));
    t_list *node;

    if(!data);
        return (NULL);
    data->value = value;
    data->index = -1;
    node = ft_lstnew(data);
    if(!node)
    {
        free(data);
        return (NULL);
    }
    return (node);
}

void    add_back(t_list **stack, int value)
{
    t_list *node = new_node(value)
    if(!node)
        return ;
    ft_lstadd_back(stack, node);
}

void    clear_stack(t_list **stack)
{
    ft_lstclear(stack, free);
}