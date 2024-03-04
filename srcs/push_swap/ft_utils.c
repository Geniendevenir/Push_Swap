/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:41:40 by adebert           #+#    #+#             */
/*   Updated: 2024/03/04 17:31:49 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_printlst(t_list  *tab)
{
    while (tab)
    {
        ft_printf("%d -> ", tab->content);
        tab = tab->next;
    }
    ft_printf("NULL\n");
}

void    lst_free(t_list **lst)
{
    t_list  *tmp;
    t_list  *current;

    if (!lst)
        return ;
    current = *lst;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *lst = NULL;
}

int      ft_full_free(t_list **lst)
{ 
        lst_free(lst);
        ft_printf("Error\n");
        return (1);
}

int    is_neg(int a, int b)
{
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    if (a > b)
        a -= b;
    else if (a < b)
        a = b - a;
    return (a);
}

int    is_neg_b(int a, int b)
{
    if (a < 0 && b < 0)
        return ((b - a) * -1);
    else
        return(a - b);
}

bool    lower_median(t_list **lst, t_list *node)
{
    int     size;

    if (ft_lstsize(*lst) % 2 == 0)
        size = ft_lstsize(*lst);
    else
        size = ft_lstsize(*lst) + 1;
    
    if (find_node(lst, node) > (size / 2))
        return (0);
    else if (find_node(lst, node) < (size / 2))
        return (1);
    return (0);
}

