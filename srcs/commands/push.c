/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:38:07 by adebert           #+#    #+#             */
/*   Updated: 2024/03/04 17:31:41 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void    pa(t_list **a, t_list **b)
{
    t_list *move;
    t_list *save;

    move = ft_lstnew((*b)->content);
    save = *b;
    ft_lstadd_front(a, move);
    *b = (*b)->next;
    free(save);
    printf("pa\n");
}

void    pb(t_list **a, t_list **b)
{
    t_list *move;
    t_list *save;
    
    move = ft_lstnew((*a)->content);
    save = *a;
    ft_lstadd_front(b, move);
    *a = (*a)->next;
    free(save);
    printf("pb\n");
} */

void    pa(t_list **a, t_list **b)
{
    t_list *move;
    t_list *save;

    save = *b;
    move = ft_lstnew((*b)->content);
    ft_lstadd_front(a, move);
    *b = (*b)->next;
    free(save);
    printf("pa\n");
}

void    pb(t_list **a, t_list **b)
{
    t_list *move;
    t_list *save;

    save = *a;
    move = ft_lstnew((*a)->content);
    ft_lstadd_front(b, move);
    *a = (*a)->next;
    free(save);
    printf("pb\n");
}
