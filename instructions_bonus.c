/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 21:11:48 by genouf            #+#    #+#             */
/*   Updated: 2022/06/08 11:54:55 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"

void	swap_c(t_m_list *master_stack, char stack_name)
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
}

void	rotate_c(t_m_list *master_stack, char stack_name)
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
}

void	reverse_rotate_c(t_m_list *master_stack, char stack_name)
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
}

void	double_action_c(t_m_list *master_stack, void (*f)(t_m_list *master_stack,
	char stack_name))
{
	(*f)(master_stack, 'q');
	(*f)(master_stack, 'w');
}
