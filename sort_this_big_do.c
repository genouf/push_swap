/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_this_big_do.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:15:57 by genouf            #+#    #+#             */
/*   Updated: 2022/06/09 16:26:27 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	process_sort_big(t_m_list *master_stack, t_c_i count_inst)
{
	if ((count_inst.count_instruct_a > 0 && count_inst.count_instruct_b > 0)
		|| (count_inst.count_instruct_a < 0
			&& count_inst.count_instruct_b < 0))
	{
		process_sort_same(master_stack, count_inst);
	}
	else
	{
		process_sort_different(master_stack, count_inst, 'a');
		process_sort_different(master_stack, count_inst, 'b');
	}
	push_a(&(master_stack->bg_sa), &(master_stack->bg_sb));
}

void	clean_end(t_m_list *master_stack, int count)
{
	int		size_lst;
	t_list	*tmp;

	tmp = master_stack->bg_sa;
	size_lst = ft_lstsize(master_stack->bg_sa);
	while (tmp->index != 0)
	{
		count++;
		tmp = tmp->next;
	}
	if (count > size_lst / 2)
		count = count - size_lst;
	if (count > 0)
	{
		count++;
		while (--count > 0)
			rotate(master_stack, 'a');
	}
	else
	{
		count--;
		while (++count < 0)
			reverse_rotate(master_stack, 'a');
	}
}

void	init_sort_big(t_m_list *master_stack)
{
	push_sort(master_stack);
	sort_small(master_stack);
}

void	choose_best_inst(t_c_i *tmp_count, t_c_i *count_inst)
{
	set_total_instruct(tmp_count);
	if (count_inst->initialized == 0 || tmp_count->total_intruct
		< count_inst->total_intruct)
	{
		count_inst->initialized = 1;
		*count_inst = *tmp_count;
	}
}

void	sort_big(t_m_list *master_stack)
{
	t_c_i	count_inst;
	t_c_i	tmp_count;
	t_list	*tmp;

	if (list_sorted(master_stack->bg_sa))
		return ;
	init_sort_big(master_stack);
	while (master_stack->bg_sb)
	{
		count_inst.count_instruct_a = 0;
		count_inst.count_instruct_b = 0;
		count_inst.initialized = 0;
		tmp = master_stack->bg_sb;
		while (tmp)
		{
			tmp_count = find_next_index(tmp, master_stack,
					ft_lstsize(master_stack->bg_sb),
					ft_lstsize(master_stack->bg_sa));
			choose_best_inst(&tmp_count, &count_inst);
			tmp = tmp->next;
		}
		process_sort_big(master_stack, count_inst);
	}
	clean_end(master_stack, 0);
}
