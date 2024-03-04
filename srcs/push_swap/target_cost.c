/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:34:41 by adebert           #+#    #+#             */
/*   Updated: 2024/03/04 17:31:46 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    a_target_b(t_list *a, t_list *b, t_list **blist)
{
    a->target = b;
    int    difference;
    int     min;
    
    min = 0;
    difference = is_neg(a->content, b->content);
    while (b)
    {
        if (a->content > b->content)
        {
            min = 1;
            if (is_neg(a->content, b->content) < difference)
            {
                difference = is_neg(a->content, b->content);
                a->target = b;
            }
        }
        b = b->next;
    }
    if (min == 0)
        a->target = whos_biggest(*blist);
}

int     find_node(t_list **lst, t_list *node)
{
    int     found;
    t_list  *current;

    current = *lst;
    found = 0;
    while(current && current->content != node->content)
    {
        current = current->next;
        found++;
    }
    return (found);
}

bool     whats_cost(t_list **lst, t_list *node)
{
    /* if (!(*lst))
        return (0); */
    if ((find_node(lst, node) +1) == ft_lstsize(*lst))
    {
        node->cost = 1;
        return (1);
    }
    if (lower_median(lst, node))
        node->cost = find_node(lst, node);
    else if (!lower_median(lst, node))
        node->cost = ft_lstsize(*lst) - find_node(lst, node);
    return (0);
}

void    give_cost(t_list **a, t_list **b, t_list *current)
{
        if (whats_cost(a, current) && whats_cost(b, current->target))
            current->cost = 1;
        else if (find_node(a, current) == 1 && find_node(b, current->target) == 1)
            current->cost = 1;
        else
        {
            whats_cost(a, current);
            whats_cost(b, current->target);
            current->cost += current->target->cost;
        }
}
void    higher_cost(t_list *current)
{
    while (current->next)
    {
        if (current->cost < current->next->cost)
            current->cost = current->next->cost;
        current = current->next;
    }
}
