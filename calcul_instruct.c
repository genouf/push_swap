/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_instruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:12:07 by genouf            #+#    #+#             */
/*   Updated: 2022/06/11 16:55:58 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_c_i *count_inst, int count, int size_stack,
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
	t_c_i *count_inst)
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

void	calcul_index_a(t_list *tmp, int index, int count)
{
	if (count == 1)
		index--;
	else if (count == 2)
	{
		index++;
		count = 0;
	}
	while (tmp)
	{
		if (tmp->index == index)
			break ;
		count++;
		tmp = tmp->next;
	}
}

t_c_i	find_next_index(t_list *b_element, t_m_list *master_stack,
	int size_b, int size_a)
{
	t_list	*tmp;
	t_c_i	count_inst;
	int		count;

	tmp = master_stack->bg_sb;
	find_index_b(b_element, tmp, size_b, &count_inst);
	tmp = master_stack->bg_sa;
	count = calcul_inst_a(master_stack, b_element);
	set_index(&count_inst, count, size_a, 'a');
	return (count_inst);
}
