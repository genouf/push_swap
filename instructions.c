/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:11:48 by genouf            #+#    #+#             */
/*   Updated: 2022/05/21 21:39:44 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_m_list *master_stack, char stack_name)
{
	t_list	*tmp;
	t_list	**begin_list;

	if (stack_name == 'a')
		begin_list = &(master_stack->bg_sa);
	else
		begin_list = &(master_stack->bg_sb);
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

void	rotate(t_m_list *master_stack, char stack_name)
{
	t_list	*first;
	t_list	*last;
	t_list	**begin_list;

	if (stack_name == 'a' || stack_name == 'q')
		begin_list = &(master_stack->bg_sa);
	else
		begin_list = &(master_stack->bg_sb);
	if (!(*begin_list) || (*begin_list)->next == NULL)
		return ;
	first = *begin_list;
	*begin_list = first->next;
	last = ft_lstlast(first);
	last->next = first;
	first->next = NULL;
	if (stack_name == 'a')
		write(1, "ra\n", 3);
	else if (stack_name == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_m_list *master_stack, char stack_name)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	**begin_list;

	if (stack_name == 'a' || stack_name == 'q')
		begin_list = &(master_stack->bg_sa);
	else
		begin_list = &(master_stack->bg_sb);
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
	else if (stack_name == 'b')
		write(1, "rrb\n", 4);
}

void	double_action(t_m_list *master_stack, void (*f)(t_m_list *master_stack, char stack_name),
	char a_name)
{
	(*f)(master_stack, 'q');
	(*f)(master_stack, 'w');
	if (a_name == 's')
		write(1, "ss\n", 3);
	else if (a_name == 'r')
		write(1, "rr\n", 3);
	else
		write(1, "rrr\n", 4);
}
