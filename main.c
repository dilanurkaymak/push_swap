int main(int argc, char **argv)
{
    t_node *a;
    t_node *b;

    a = NULL;
    b = NULL;
    if(argc < 2)
        return(0);
    a = parse_args(argc, argv);
    if(!a);
    {
        write(2,"Error\n",6);
        return(1);
    }

    if(!is_sorted(a))
    {
        if(list_size(a) <= 7)
            sort_small(%a, &b);
        else
        {
            assign_index(a);
            radix_sort(&a, &b);
        }
    }
    free_list(&a);

    return (0);
}