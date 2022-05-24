/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_this_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:55 by genouf            #+#    #+#             */
/*   Updated: 2022/05/24 11:17:35 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_total_instruct(t_c_i *count_inst, int *count_total)
{
	if (count_inst->count_instruct_a > 0)
		*count_total += count_inst->count_instruct_a;
	else
		*count_total += count_inst->count_instruct_a * -1;
	if (count_inst->count_instruct_b > 0)
		*count_total += count_inst->count_instruct_b;
	else
		*count_total += count_inst->count_instruct_b * -1;
}

void	set_total_instruct(t_c_i *count_inst)
{
	int	count_total;

	count_total = 0;
	if ((count_inst->count_instruct_a > 0 && count_inst->count_instruct_b > 0)
		|| (count_inst->count_instruct_a < 0
			&& count_inst->count_instruct_b < 0))
	{
		if (count_inst->count_instruct_a > 0)
		{
			if (count_inst->count_instruct_a >= count_inst->count_instruct_b)
				count_total = count_inst->count_instruct_a;
			else
				count_total = count_inst->count_instruct_b;
		}
		else
		{
			if (count_inst->count_instruct_a <= count_inst->count_instruct_b)
				count_total = count_inst->count_instruct_a * -1;
			else
				count_total = count_inst->count_instruct_b * -1;
		}
	}
	else
		process_total_instruct(count_inst, &count_total);
	count_inst->total_intruct = count_total;
}

void	process_sort_same(t_m_list *master_stack, t_c_i count_inst)
{
	char	tab_info[2];

	if (count_inst.count_instruct_a > 0)
	{
		if (count_inst.count_instruct_a > count_inst.count_instruct_b)
		{
			tab_info[0] = '+';
			tab_info[1] = 'a';
			action_same(master_stack, count_inst.count_instruct_a,
				count_inst, tab_info);
		}
		else
		{
			tab_info[0] = '+';
			tab_info[1] = 'b';
			action_same(master_stack, count_inst.count_instruct_b,
				count_inst, tab_info);
		}
	}
	else
		process_sort_same_minus(master_stack, count_inst, tab_info);
}

int	find_inf_median(t_list *begin_list, int median)
{
	while (begin_list)
	{
		if (begin_list->index < median)
			return (1);
		begin_list = begin_list->next;
	}
	return (0);
}

void	push_sort(t_m_list *master_stack)
{
	int	median;

	median = ft_lstsize(master_stack->bg_sa) / 2;
	while (find_inf_median(master_stack->bg_sa, median))
	{
		if (master_stack->bg_sa->index < median)
			push_b(&(master_stack->bg_sa), &(master_stack->bg_sb));
		else
			rotate(master_stack, 'a');
	}
	clean_for_three(master_stack);
}
