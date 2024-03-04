/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:41:40 by adebert           #+#    #+#             */
/*   Updated: 2024/03/04 17:31:48 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->target = NULL;
	return (node);
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*count;

	count = lst;
	if (!count)
		return (0);
	i = 0;
	while (count)
	{
		count = count->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *node)
{
	t_list	*last_node;

	if (lst)
	{
		if (*lst)
		{
			last_node = ft_lstlast(*lst);
			last_node->next = node;
		}
		else
			*lst = node;
		last_node = ft_lstlast(*lst);
		last_node->next = NULL;
	}
}
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
    if (!(*lst))
    {
        *lst = new;
        return ;
    }
    
	new->next = *lst;
	*lst = new;
}
