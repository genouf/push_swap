/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_this.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:38:09 by genouf            #+#    #+#             */
/*   Updated: 2022/05/16 21:54:22 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_mini(t_list *begin_list)
{
	int	tmp;

	tmp = begin_list->content;
	while (begin_list)
	{
		if (begin_list->content < tmp)
			tmp = begin_list->content;
		begin_list = begin_list->next;
	}
	return (tmp);
}

int	list_sorted(t_list *begin_list)
{
	int	tmp;

	tmp = begin_list->content;
	begin_list = begin_list->next;
	while (begin_list)
	{
		if (begin_list->content < tmp)
			return (0);
		tmp = begin_list->content;
		begin_list = begin_list->next;
	}
	return (1);
}

void	sort_min(m_list *master_stack)
{
	int	mini;
	int	pushed;

	while (!list_sorted(master_stack->bg_sa))
	{
		pushed = 0;
		mini = find_mini(master_stack->bg_sa);
		while (!pushed)
		{
			if (master_stack->bg_sa->content == mini)
			{
				push_b(&(master_stack->bg_sa), &(master_stack->bg_sb));
				pushed = 1;
			}
			else if (master_stack->bg_sa->next->content == mini)
				swap(&(master_stack->bg_sa), 'a');
			else if (ft_lstlast(master_stack->bg_sa)->content == mini)
				reverse_rotate(&(master_stack->bg_sa), 'a');
			else
				rotate(&(master_stack->bg_sa), 'a');
		}
	}
	while (master_stack->bg_sb != NULL)
		push_a(&(master_stack->bg_sa), &(master_stack->bg_sb));
}
