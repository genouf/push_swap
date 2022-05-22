/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_instruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:12:07 by genouf            #+#    #+#             */
/*   Updated: 2022/05/22 23:06:27 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_exist(int index, t_list *bg_sa)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = bg_sa;
	while (tmp)
	{
		if (tmp->index == index - 1)
			count += 1;
		tmp = tmp->next;
	}
	tmp = bg_sa;
	while (tmp)
	{
		if (tmp->index == index + 1)
			count += 2;
		tmp = tmp->next;
	}
	return (count);
}

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

int	calcul_index_a(t_list *tmp, int index, int count)
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
			return (count);
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
	count = index_exist(b_element->index, tmp);
	if (count == 1 || count == 2)
		count = calcul_index_a(tmp, b_element->index, count);
	else if (count == 3)
	{
		if (calcul_index_a(tmp, b_element->index, 1)
			>= calcul_index_a(tmp, b_element->index, 2))
			count = calcul_index_a(tmp, b_element->index, 1);
		else
			count = calcul_index_a(tmp, b_element->index, 2);
	}
	set_index(&count_inst, count, size_a, 'a');
	if (index_exist(b_element->index, tmp) == 0)
		count_inst.index_ok = 0;
	else
		count_inst.index_ok = 1;
	return (count_inst);
}
