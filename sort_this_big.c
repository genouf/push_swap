/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_this_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:23:55 by genouf            #+#    #+#             */
/*   Updated: 2022/05/20 05:12:46 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_count_inst	find_next_index(t_list *b_element, t_m_list *master_stack, int size_b, int size_a)
{
	t_list			*tmp;
	t_count_inst	count_inst;
	int				count;

	count = 0;
	tmp = master_stack->bg_sb;
	while (tmp != b_element)
	{
		count++;
		tmp = tmp->next;
	}
	if (count > (size_b / 2))
		count_inst.count_instruct_b = count - size_b;
	else
		count_inst.count_instruct_b = count;
	count = 1;
	tmp = master_stack->bg_sa;
	while (tmp && tmp->index != (b_element->index - 1))
	{
		printf("count:%d\n", count);
		count++;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		count_inst.count_instruct_a = 0;
	else
	{
		if (count > (size_a / 2))
			count_inst.count_instruct_a = count - size_a;
		else
			count_inst.count_instruct_a = count;
	}
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