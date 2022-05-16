/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:11:48 by genouf            #+#    #+#             */
/*   Updated: 2022/05/16 21:46:11 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **begin_list, char stack_name)
{
	t_list	*tmp;

	if (!(*begin_list) || (*begin_list)->next == NULL)
		return ;
	tmp = *begin_list;
	*begin_list = (*begin_list)->next;
	tmp->next = (*begin_list)->next;
	(*begin_list)->next = tmp;
	if (stack_name == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	rotate(t_list **begin_list, char stack_name)
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
	if (stack_name == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_list **begin_list, char stack_name)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*begin_list) || (*begin_list)->next == NULL)
		return ;
	tmp = *begin_list;
	while ((*begin_list)->next->next)
		*begin_list = (*begin_list)->next;
	tmp2 = (*begin_list)->next;
	(*begin_list)->next = NULL;
	*begin_list = tmp2;
	(*begin_list)->next = tmp;
	if (stack_name == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	double_action(m_list *master_stack, void (*f)(t_list **begin_list),
	char a_name)
{
	(*f)(&(master_stack->bg_sa));
	(*f)(&(master_stack->bg_sb));
	if (a_name == 's')
		write(1, "ss\n", 3);
	else if (a_name == 'r')
		write(1, "rr\n", 3);
	else
		write(1, "rrr\n", 4);
}
