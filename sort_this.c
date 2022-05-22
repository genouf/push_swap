/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_this.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:38:09 by genouf            #+#    #+#             */
/*   Updated: 2022/05/22 21:00:07 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_sorted(t_list *begin_list)
{
	int	tmp;

	tmp = begin_list->content;
	begin_list = begin_list->next;
	while (begin_list)
	{
		if (begin_list->content < tmp)
			return (0);
		tmp = begin_list->content;
		begin_list = begin_list->next;
	}
	return (1);
}

t_list	*find_min(t_list *begin_list)
{
	int		tmp;
	t_list	*result;

	tmp = begin_list->content;
	result = begin_list;
	while (begin_list)
	{
		if (begin_list->content < tmp)
		{
			tmp = begin_list->content;
			result = begin_list;
		}
		begin_list = begin_list->next;
	}
	return (result);
}

t_list	*find_max(t_list *begin_list)
{
	int		tmp;
	t_list	*result;

	tmp = begin_list->content;
	result = begin_list;
	while (begin_list)
	{
		if (begin_list->content > tmp)
		{
			tmp = begin_list->content;
			result = begin_list;
		}
		begin_list = begin_list->next;
	}
	return (result);
}

void	clean_for_three(t_m_list *master_stack)
{
	int	size;

	size = ft_lstsize(master_stack->bg_sa);
	while (size > 3)
	{
		push_b(&(master_stack->bg_sa), &(master_stack->bg_sb));
		size--;
	}
}

void	sort_small(t_m_list *master_stack)
{
	t_list	*max;
	t_list	*min;
	t_list	**begin_list;

	begin_list = &(master_stack->bg_sa);
	max = find_max(*begin_list);
	min = find_min(*begin_list);
	if ((*begin_list)->next == min && (*begin_list)->next->next == max)
		swap(master_stack, 'a');
	else if ((*begin_list)->next->next == min && (*begin_list)->next == max)
		reverse_rotate(master_stack, 'a');
	else if (*begin_list == max && (*begin_list)->next == min)
		rotate(master_stack, 'a');
	else if (*begin_list == max && (*begin_list)->next->next == min)
	{
		rotate(master_stack, 'a');
		swap(master_stack, 'a');
	}
	else if (*begin_list == min && (*begin_list)->next == max)
	{
		reverse_rotate(master_stack, 'a');
		swap(master_stack, 'a');
	}
}
