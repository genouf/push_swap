/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:11:48 by genouf            #+#    #+#             */
/*   Updated: 2022/05/15 18:18:48 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **begin_list)
{
	t_list	*tmp;

	if (!(*begin_list) || (*begin_list)->next == NULL)
		return ;
	tmp = *begin_list;
	*begin_list = (*begin_list)->next;
	tmp->next = (*begin_list)->next;
	(*begin_list)->next = tmp;	
}

void	push_a(t_list **begin_list_a, t_list **begin_list_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*begin_list_b))
		return ;
	tmp = (*begin_list_b)->next;
	tmp2 = *begin_list_a;
	*begin_list_a = *begin_list_b;
	(*begin_list_a)->next = tmp2;
	*begin_list_b = tmp;
}

void	push_b(t_list **begin_list_a, t_list **begin_list_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*begin_list_a))
		return ;
	tmp = (*begin_list_a)->next;
	tmp2 = *begin_list_b;
	*begin_list_b = *begin_list_a;
	(*begin_list_b)->next = tmp2;
	*begin_list_a = tmp;
}

void	rotate(t_list **begin_list)
{
	t_list	*first;
	t_list	*last;

	if (!(*begin_list) || (*begin_list)->next == NULL)
		return ;
	first = *begin_list;
	*begin_list = first->next;
	last = ft_lstlast(first);
	last->next = first;
	first->next = NULL;
}

void	double_action(m_list master_stack, void (*f)(t_list **begin_list))
{
	(*f)(&(master_stack.bg_sa));
	(*f)(&(master_stack.bg_sb));
}