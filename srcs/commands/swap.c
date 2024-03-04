/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:20:35 by adebert           #+#    #+#             */
/*   Updated: 2024/03/04 17:03:32 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_list **a)
{
    long    save;

    if (ft_lstsize(*a) <= 1)
        return ;
    save = (*a)->content;
    (*a)->content = (*a)->next->content;
    (*a)->next->content = save;
    printf("sa\n");
}

void    sb(t_list **b)
{
    long    save;

    if (ft_lstsize(*b) <= 1)
        return ;
    save = (*b)->content;
    (*b)->content = (*b)->next->content;
    (*b)->next->content = save;
    printf("sb\n");
}

void    ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
}


