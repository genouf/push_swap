/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_this_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:55 by genouf            #+#    #+#             */
/*   Updated: 2022/05/22 21:10:31 by genouf           ###   ########.fr       */
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
