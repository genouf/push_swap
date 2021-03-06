/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_i_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:46:55 by genouf            #+#    #+#             */
/*   Updated: 2022/05/24 11:25:23 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cyclic_part(t_list *begin_list)
{
	while (begin_list->next->index > begin_list->index)
		begin_list = begin_list->next;
	return (begin_list);
}

int	calculate_count(t_list *b_elem, t_list *lst)
{
	int	count;

	count = 1;
	while (lst->next)
	{
		if (lst->index < lst->next->index)
		{
			if (b_elem->index > lst->index && b_elem->index < lst->next->index)
				return (count);
		}
		else
		{
			if (b_elem->index < lst->index && b_elem->index < lst->next->index)
				return (count);
		}
		count++;
		lst = lst->next;
	}
	return (-1);
}

int	calcul_cyclic(t_list *lst, t_list *cyclic_part)
{
	int	count;

	count = 1;
	while (lst != cyclic_part)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	calcul_inst_a(t_m_list *master_stack, t_list *b_elem)
{
	int		count;

	if (master_stack->bg_sa->index > ft_lstlast(master_stack->bg_sa)->index)
	{
		if (b_elem->index < master_stack->bg_sa->index && b_elem->index
			> ft_lstlast(master_stack->bg_sa)->index)
		{
			count = 0;
		}
		else
			count = calculate_count(b_elem, master_stack->bg_sa);
	}
	else
	{
		if (b_elem->index < master_stack->bg_sa->index || b_elem->index
			> ft_lstlast(master_stack->bg_sa)->index)
			count = 0;
		else
			count = calculate_count(b_elem, master_stack->bg_sa);
	}
	if (count == -1)
		count = calcul_cyclic(master_stack->bg_sa,
				find_cyclic_part(master_stack->bg_sa));
	return (count);
}
