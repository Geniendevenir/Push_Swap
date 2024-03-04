/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:10:06 by adebert           #+#    #+#             */
/*   Updated: 2024/03/04 17:31:43 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_list **a)
{
    t_list      *move;
    t_list      *save;
    t_list      *current;

    move = ft_lstnew(ft_lstlast(*a)->content);
    ft_lstadd_front(a, move);
    save = ft_lstlast(*a);
    current = *a;
    while (current->next)
    {
        if (current->next->next == NULL)
        {
            current->next = NULL;
            free(save);
            break ;
        }
        current = current->next;
    }
    printf("rra\n");
}

/* void    rrb(t_list **b)
{
    t_list    *move;

    move = ft_lstnew(ft_lstlast(*b)->content);
    ft_lstadd_front(b, move);
    free(ft_lstlast(*b));
    printf("rrb\n");
} */

void    rrb(t_list **b)
{
    t_list      *move;
    t_list      *current;
    t_list      *save;

    move = ft_lstnew(ft_lstlast(*b)->content);
    ft_lstadd_front(b, move);
    save = ft_lstlast(*b);
    current = *b;
    while (current->next)
    {
        if (current->next->next == NULL)
        {
            current->next = NULL;
            free(save);
            break ;
        }
        current = current->next;
    }
    printf("rrb\n");
}

void    rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}

//5 48 67 145 -34 -800 24 12 33 128 6 9 1 -5 -10