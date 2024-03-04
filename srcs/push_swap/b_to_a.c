/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:15:08 by adebert           #+#    #+#             */
/*   Updated: 2024/03/04 17:31:45 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list    *whos_lowest(t_list *a)
{
    t_list *lowest;

    lowest = a;
    while (a)
    {
        if (lowest->content > a->content)
            lowest = a;
        a = a->next;
    }
    return (lowest);
}

void    b_target_a(t_list *a, t_list *b, t_list **alist)
{
    b->target = a;
    int    difference;
    int     max;
    
    max = 0;
    difference = is_neg_b(a->content, b->content);
    while (a)
    {
        if (a->content > b->content)
        {
            max = 1;
            if (is_neg_b(a->content, b->content) < difference)
            {
                difference = is_neg_b(a->content, b->content);
                b->target = a;
            }
        }
        a = a->next;
    }
    if (max == 0)
        b->target = whos_lowest(*alist);
}
