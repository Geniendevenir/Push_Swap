/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:25:25 by adebert           #+#    #+#             */
/*   Updated: 2024/02/27 15:02:49 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_list
{
	long		content;
	int		cost;
	
	struct s_list	*target;
	struct s_list	*next;

}					t_list;

t_list	*ft_lstnew(long content);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *node);
void    ft_printlst(t_list  *tab);
void	ft_lstadd_front(t_list **lst, t_list *new);

//algo
void	sort_three(t_list **a);
bool    check_three(t_list **a, t_list **b);
bool    is_sorted(t_list *a);
void    sort_stack(t_list **a, t_list **b);
bool     whats_cost(t_list **lst, t_list *node);
bool    lower_median(t_list **lst, t_list *node);
int     find_node(t_list **lst, t_list *node);
void    top_of_a(t_list **a, t_list **b, t_list *node);
void    top_of_b(t_list **b, t_list *node);
void    give_cost(t_list **a, t_list **b, t_list *current);
void    higher_cost(t_list *current);

//a_to_b
void    a_target_b(t_list *a, t_list *b, t_list **blist);

//b_to_a
void    b_target_a(t_list *a, t_list *b, t_list **alist);
int    is_neg_b(int a, int b);


//check inputs
int	ft_init_check(char **argv, t_list **a);
int     ft_checknumber(char *lst);
int	ft_checklist(t_list **a);
long    *malloc_tab(t_list **a, int size);
bool	check_double(long* tab, int size);

//free
int      ft_full_free(t_list **lst);
void    lst_free(t_list **lst);

//operations
void    sa(t_list **a);
void    sb(t_list **b);
void    ss(t_list **a, t_list **b);
void    pa(t_list **a, t_list **b);
void    pb(t_list **a, t_list **b);
void    ra(t_list **a);
void    rb(t_list **b);
void    rr(t_list **a, t_list **b);
void    rra(t_list **a);
void    rrb(t_list **b);
void    rrr(t_list **a, t_list **b);

//utils
void    easy_life(t_list *a, t_list *b);
int    is_neg(int a, int b);
t_list    *whos_lowest(t_list *a);
t_list    *whos_biggest(t_list *b);

int main(int argc, char **argv);

#endif
