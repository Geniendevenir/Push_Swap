/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checklist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:03:25 by adebert           #+#    #+#             */
/*   Updated: 2024/03/04 17:31:47 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_checknumber(char *lst)
{
    int     i;

    i = 0;
    while (lst[i])
    {
        if (!(lst[i] == ' ' || lst[i] == '-' || (lst[i] >= '0' && lst[i] <= '9')))
            return (1);
        i++;
    }
    return (0);  
}

long    *malloc_tab(t_list **a, int size)
{
    long	*tab;
    t_list  *current;
    int     i;

    current = *a;
    tab = malloc(sizeof(long) * size + 1);
	if (!tab)
        	return (0);
    i = 0;
    while (current)
    {
        tab[i] = current->content;
        current = current->next;
        i++;
    }
    tab[i] = 0;
    return (tab);
}

bool    check_double(long* tab, int size)
{
    int     i;
    int     j;
    
	j = 0;
    i = 1;
	while (i < size)
    	{
        	while (j < i)
        	{
            		if (tab[i] == tab[j])
                        return (1);
            		j++;
        	}
        	j = 0;
        	i++;
    	}
    return (0);
}
int	ft_checklist(t_list **a)
{
	long	*tab;
	int	    size;
	
	size = ft_lstsize(*a);
	if (size < 2)
		return (1);
    tab = malloc_tab(a, size);
    if (check_double(tab, size))
    {
        free(tab);
        return (1);
    }
    free(tab);
    return (0);
}
int    ft_init_check(char **argv, t_list **a)
{
    t_list  *node;
    int     i;

    i = 0;
    while (argv[i])
    {
        if (ft_checknumber(argv[i]))
            return(ft_full_free(a));
        node = ft_lstnew(ft_atoi(argv[i]));
        if (node->content > INT_MAX || node->content < INT_MIN)
        {
            free(node);
            return (ft_full_free(a));
        }
        ft_lstadd_back(a, node);
        i++;
    }
    if (ft_checklist(a))
        return (ft_full_free(a));
    return (0);
}
