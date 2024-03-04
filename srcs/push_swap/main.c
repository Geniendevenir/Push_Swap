/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:31:50 by adebert           #+#    #+#             */
/*   Updated: 2024/03/04 17:31:49 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;

    a = NULL;
    b = NULL;
    if (argc != 2 || !argv[1][0])
        return (0);
    argv = ft_split(argv[1], ' ');
    if (ft_init_check(argv, &a) == 1)
    {
        ft_free(argv);
        lst_free(&a);
        return (0);
    }
    ft_free(argv);
    /* ft_printf("A = ");
    ft_printlst(a);
    ft_printf("B = ");
    ft_printlst(b); */
    if (!is_sorted(a))
    {
        if (ft_lstsize(a) == 2)
            ra(&a);
        else if (ft_lstsize(a) == 3)
            sort_three(&a);
        else
            sort_stack(&a, &b);
    }
    /* ft_printf("A = ");
    ft_printlst(a);
    ft_printf("B = ");
    ft_printlst(b); */
    lst_free(&a);
    lst_free(&b);
    return (0);
}
