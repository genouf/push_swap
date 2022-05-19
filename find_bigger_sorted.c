/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bigger_sorted.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:07:59 by genouf            #+#    #+#             */
/*   Updated: 2022/05/19 12:08:01 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*void	ft_lstprintsorted(t_sortlist sorted_list)
{
	t_list	*tmp;

	tmp = sorted_list.first;
	while (tmp && tmp != sorted_list.last->next)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}*/

t_tosort	init_find_bigger(t_list *begin_list, t_sortlist *sorted_list)
{
	t_tosort	tosort;

	sorted_list->first = NULL;
	sorted_list->last = NULL;
	tosort.tmp_first = begin_list;
	tosort.precedent = begin_list;
	tosort.max_count = 0;
	tosort.count = 0;
	tosort.tmp = begin_list->content;
	return (tosort);
}

void	set_sorted_list(t_sortlist *sorted_list, t_tosort *tosort)
{
	if (tosort->count > tosort->max_count)
	{
		tosort->max_count = tosort->count;
		sorted_list->first = tosort->tmp_first;
		sorted_list->last = tosort->precedent;
	}
}

t_sortlist find_bigger_sorted(t_list *begin_list)
{
	t_sortlist	sorted_list;
	t_tosort	tosort;

	tosort = init_find_bigger(begin_list, &sorted_list);
	begin_list = begin_list->next;
	while (begin_list)
	{
		if (tosort.tmp < begin_list->content)
			tosort.count++;
		else
		{
			set_sorted_list(&sorted_list, &tosort);	
			tosort.count = 0;
			tosort.tmp_first = begin_list;
		}
		tosort.precedent = begin_list;
		tosort.tmp = begin_list->content;
		begin_list = begin_list->next;
	}
	set_sorted_list(&sorted_list, &tosort);	
	return (sorted_list);
}

void	clean_sorted_list(t_m_list *master_stack, t_sortlist sorted_list, int count)
{
	t_list	*tmp;

	tmp = master_stack->bg_sa;
	while (tmp != sorted_list.first)
	{
		count ++;
		tmp = tmp->next;
	}
	while (count != 0)
	{
		push_b(&(master_stack->bg_sa), &(master_stack->bg_sb));
		count--;	
	}
	tmp = sorted_list.last;
	while (tmp->next)
	{
		count++;
		tmp = tmp->next;
	}
	while (count != 0)
	{
		reverse_rotate(&(master_stack->bg_sa), 'a');
		push_b(&(master_stack->bg_sa), &(master_stack->bg_sb));
		count--;
	}
}