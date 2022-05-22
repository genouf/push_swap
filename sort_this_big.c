/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_this_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:55 by genouf            #+#    #+#             */
/*   Updated: 2022/05/22 13:43:49 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	index_exist(int	index, t_list *bg_sa)
{
	while (bg_sa)
	{
		if (bg_sa->index == index - 1)
			return (1);
		bg_sa = bg_sa->next;
	}
	return (0);
}

void	set_index(t_count_inst *count_inst, int count, int size_stack,
	char name)
{
	if (name == 'a')
	{
		if (count > (size_stack / 2))
			count_inst->count_instruct_a = count - size_stack;
		else
			count_inst->count_instruct_a = count;
	}
	else
	{
		if (count > (size_stack / 2))
			count_inst->count_instruct_b = count - size_stack;
		else
			count_inst->count_instruct_b = count;
	}
}

void	find_index_b(t_list *b_element, t_list *tmp, int size_b,
	t_count_inst *count_inst)
{
	int	count;

	count = 0;
	while (tmp)
	{
		if (tmp == b_element)
		{
			set_index(count_inst, count, size_b, 'b');
			break ;
		}
		count++;
		tmp = tmp->next;
	}
}

t_count_inst	find_next_index(t_list *b_element, t_m_list *master_stack,
	int size_b, int size_a)
{
	t_list			*tmp;
	t_count_inst	count_inst;
	int				count;

	tmp = master_stack->bg_sb;
	find_index_b(b_element, tmp, size_b, &count_inst);
	//ft_printf("instruct b:%d\n", count_inst.count_instruct_b);
	count = 1;
	tmp = master_stack->bg_sa;
	while (tmp)
	{
		if (tmp->index == (b_element->index - 1))
		{
			set_index(&count_inst, count, size_a, 'a');
			break ;
		}
		count++;
		tmp = tmp->next;
	}
	//ft_printf("instruct a:%d\n", count_inst.count_instruct_a);
	if (tmp == NULL || !index_exist(b_element->index, master_stack->bg_sa))
		count_inst.index_ok = 0;
	else
		count_inst.index_ok = 1;
	return (count_inst);
}

void	process_total_instruct(t_count_inst *count_inst, int *count_total)
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

void	set_total_instruct(t_count_inst *count_inst)
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
