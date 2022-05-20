/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_this_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:55 by genouf            #+#    #+#             */
/*   Updated: 2022/05/20 13:34:08 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	set_index(t_count_inst *count_inst, int count, int size_stack,
	char name)
{
	if (name == 'a')
	{
		if (count > (size_stack / 2))
			count_inst->count_instruct_a = count - size_stack - 1;
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
	if (tmp == NULL)
		count_inst.index_ok = 0;
	else
		count_inst.index_ok = 1;
	return (count_inst);
}

/*void	sort_big(t_m_list *master_stack, int stack_size)
{
	t_sortlist	sorted_list;

	sorted_list = find_bigger_sorted(master_stack->bg_sa);
	if (size_sorted_list(sorted_list) < 4)
		clean_for_three(master_stack);
	else
		clean_sorted_list(&master_stack, sorted_list, 0);
	while (master_stack->bg_sb)
	{
		
	}	
}*/