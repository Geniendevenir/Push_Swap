/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:11:15 by adebert           #+#    #+#             */
/*   Updated: 2024/03/04 17:31:46 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list    *whos_biggest(t_list *b)
{
    t_list  *biggest;
    
    biggest = b;
    while (b)
    {
        if (biggest->content < b->content)
            biggest = b;
        b = b->next;
    }
    return (biggest);
}

void    top_of_a(t_list **a, t_list **b, t_list *node)
{
    t_list  *save;

    save = ft_lstnew(node->content);
    save->target = node->target;
    while (find_node(a, save) != 0)
    {
        if (lower_median(a, save))
        {
            if (whats_cost(a, save) && whats_cost(b, save->target))
                rr(a, b);
            else
                ra(a);
        }
        else if (!lower_median(a, save))
        {
            if (whats_cost(a, save) && whats_cost(b, save->target))
                rrr(a, b);
            else
                rra(a);
        }
    }
    free(save);
}

void    top_of_b(t_list **b, t_list *node)
{
    t_list  *save;

    save = ft_lstnew(node->content);
    while (find_node(b, save) != 0)
    {

        if (lower_median(b, save))
        {
            rb(b);
        }
        else if (!lower_median(b, save))
            rrb(b);
    }
    free(save);
}

