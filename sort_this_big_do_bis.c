/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_this_big_do_bis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 19:48:36 by genouf            #+#    #+#             */
/*   Updated: 2022/05/22 21:17:31 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_process_sort_different(t_c_i count_inst, char stack)
{
	int	count_instruct;

	if (stack == 'a')
		count_instruct = count_inst.count_instruct_a;
	else
		count_instruct = count_inst.count_instruct_b;
	return (count_instruct);
}

void	process_sort_different(t_m_list *master_stack, t_c_i count_inst,
	char stack)
{
	int	count_instruct;

	count_instruct = init_process_sort_different(count_inst, stack);
	if (count_instruct == 0)
		return ;
	if (count_instruct < 0)
	{
		while (count_instruct < 0)
		{
			reverse_rotate(master_stack, stack);
			count_instruct++;
		}
	}
	else if (count_instruct > 0)
	{
		while (count_instruct > 0)
		{
			rotate(master_stack, stack);
			count_instruct--;
		}
	}
}

void	process_action_same(t_m_list *master_stack, int tmp, int count_inst_min,
	char stack_info)
{
	while (count_inst_min < 0)
	{
		double_action(master_stack, &reverse_rotate, 'w');
		count_inst_min++;
		tmp++;
	}
	while (tmp < 0)
	{
		reverse_rotate(master_stack, stack_info);
		tmp++;
	}
}

void	action_same(t_m_list *master_stack, int tmp, t_c_i count_inst,
	char *tab_info)
{
	int		count_inst_min;
	char	stack_info;

	stack_info = tab_info[1];
	if (stack_info == 'a')
		count_inst_min = count_inst.count_instruct_b;
	else
		count_inst_min = count_inst.count_instruct_a;
	if (tab_info[0] == '+')
	{
		while (count_inst_min > 0)
		{
			double_action(master_stack, &rotate, 'r');
			count_inst_min--;
			tmp--;
		}
		while (tmp > 0)
		{
			rotate(master_stack, stack_info);
			tmp--;
		}
	}
	else
		process_action_same(master_stack, tmp, count_inst_min, stack_info);
}

void	process_sort_same_minus(t_m_list	*master_stack, t_c_i count_inst,
	char *tab_info)
{
	if (count_inst.count_instruct_a < count_inst.count_instruct_b)
	{
		tab_info[0] = '-';
		tab_info[1] = 'a';
		action_same(master_stack, count_inst.count_instruct_a,
			count_inst, tab_info);
	}
	else
	{
		tab_info[0] = '-';
		tab_info[1] = 'b';
		action_same(master_stack, count_inst.count_instruct_b,
			count_inst, tab_info);
	}
}
