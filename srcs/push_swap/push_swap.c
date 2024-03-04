/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:41:40 by adebert           #+#    #+#             */
/*   Updated: 2024/03/04 17:31:47 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    is_sorted(t_list *a)
{
    if (!a)
    	return (1);
    while(a->next)
    {
        if (a->content > a->next->content)
            return (0);
        a = a->next;
    }
    return (1);
}

void    sort_three(t_list **a)
{
    if ((*a)->content > (*a)->next->content)
        sa(a);
    if ((*a)->next->content > (*a)->next->next->content)
        rra(a);
    if ((*a)->content > (*a)->next->content)
        sa(a);
}

bool    check_three(t_list **a, t_list **b)
{
    if (ft_lstsize(*a) == 3)
    {
        sort_three(a);
        return(1);
    }
    else if (ft_lstsize(*a) == 4)
    {
        pb(a, b);
        sort_three(a);
        pa(a, b);
        while (find_node(a, whos_lowest(*a)) != 0)
        {
        if (lower_median(a, whos_lowest(*a)))
            ra(a);
        else if (!lower_median(a, whos_lowest(*a)))
            rra(a);
        }
        return(1);
    }
    else
    {
        pb(a, b);
        pb(a, b);
    }
    return (0);
}

void    sort_stack(t_list **a, t_list **b)
{
    t_list    *current;

    if (check_three(a, b) == 1)
        return ;
    while (ft_lstsize(*a) > 3)
    {
        current = *a;
        while (current)
        {
            a_target_b(current, *b, b);
            give_cost(a, b, current);
            current = current->next;
        }
        current = *a;
        higher_cost(current);
        top_of_a(a, b, current);
        top_of_b(b, current->target);
        pb(a, b);
    }
    sort_three(a);
    current = *b;
    while (ft_lstsize(*b) != 0)
    {
        while (current)
        {
            b_target_a(*a, current, a);
            give_cost(b, a, current);
            current = current->next;
        }
        current = *b;
        higher_cost(current);
        top_of_a(b, a, current);
        top_of_b(a, current->target);
        pa(a, b);
    }
    while (find_node(a, whos_lowest(*a)) != 0)
    {
        if (lower_median(a, whos_lowest(*a)))
            ra(a);
        else if (!lower_median(a, whos_lowest(*a)))
            rra(a);
    }
    /* printf("B = "); */
    
    /* ft_printlst(*b); */
}
