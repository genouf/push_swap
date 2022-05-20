/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_this_big_do.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:15:57 by genouf            #+#    #+#             */
/*   Updated: 2022/05/20 15:17:49 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*void	sort_big(t_m_list *master_stack, int stack_size)
{
	t_sortlist		sorted_list;
	t_count_inst	count_inst;
	t_count_inst	tmp_count;
	t_list			*tmp;

	count_inst.total_intruct = -1;
	sorted_list = find_bigger_sorted(master_stack->bg_sa);
	if (size_sorted_list(sorted_list) < 4)
		clean_for_three(master_stack);
	else
		clean_sorted_list(&master_stack, sorted_list, 0);
	while (master_stack->bg_sb)
	{
		tmp = master_stack->bg_sb;
		while (tmp)
		{
			tmp_count = find_next_index(tmp, master_stack, ft_lstsize(master_stack->bg_sb), ft_lstsize(master_stack->bg_sa));
			if (tmp_count.index_ok == 1)
			{
				set_total_instruct(&tmp_count);
				if (tmp_count.total_intruct > count_inst.total_intruct)
					count_inst = tmp_count;
			}
			tmp = tmp->next;
		}
	}	
}*/