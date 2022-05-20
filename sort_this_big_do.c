/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_this_big_do.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:15:57 by genouf            #+#    #+#             */
/*   Updated: 2022/05/20 18:24:30 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	init_process_sort_different(t_count_inst count_inst, char stack)
{
	int	count_instruct;

	if (stack == 'a')
		count_instruct = count_inst.count_instruct_a;
	else
		count_instruct = count_inst.count_instruct_b;
	return (count_instruct);
}

void	process_sort_different(t_m_list *master_stack, t_count_inst count_inst, char stack)
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

void	process_action_same(t_m_list *master_stack, int tmp, int count_inst_min, char stack_info)
{
	while (count_inst_min < 0)
	{
		double_action(master_stack, &reverse_rotate, stack_info);
		count_inst_min++;
		tmp++;
	}
	while (tmp < 0)
	{
		reverse_rotate(master_stack, stack_info);
		tmp++;
	}
}

void	action_same(t_m_list *master_stack, int tmp, t_count_inst count_inst, char *tab_info)
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
			double_action(master_stack, &rotate, stack_info);
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

void	process_sort_same_minus(t_m_list	*master_stack, t_count_inst count_inst, char *tab_info)
{
	if (count_inst.count_instruct_a < count_inst.count_instruct_b)
	{
		tab_info[0] = '-';
		tab_info[1] = 'a';
		action_same(master_stack, count_inst.count_instruct_a, count_inst, tab_info);
	}
	else
	{
		tab_info[0] = '-';
		tab_info[1] = 'b';
		action_same(master_stack, count_inst.count_instruct_b, count_inst, tab_info);
	}
}

void	process_sort_same(t_m_list *master_stack, t_count_inst count_inst)
{
	char	tab_info[2];
	
	if (count_inst.count_instruct_a > 0)
	{
		if (count_inst.count_instruct_a > count_inst.count_instruct_b)
		{
			tab_info[0] = '+';
			tab_info[1] = 'a';
			action_same(master_stack, count_inst.count_instruct_a, count_inst, tab_info);
		}
		else
		{
			tab_info[0] = '+';
			tab_info[1] = 'b';
			action_same(master_stack, count_inst.count_instruct_b, count_inst, tab_info);
		}
	}
	else
		process_sort_same_minus(master_stack, count_inst, tab_info);
}

void	process_sort_big(t_m_list *master_stack, t_count_inst count_inst)
{
	if ((count_inst.count_instruct_a > 0 && count_inst.count_instruct_b > 0)
		|| (count_inst.count_instruct_a < 0
			&& count_inst.count_instruct_b < 0))
	{
		process_sort_same(master_stack, count_inst);
	}
	else
	{
		process_sort_different(master_stack, count_inst, 'a');		
		process_sort_different(master_stack, count_inst, 'b');
	}
	push_a(&(master_stack->bg_sa), &(master_stack->bg_sb));
}

void	sort_big(t_m_list *master_stack)
{
	t_sortlist		sorted_list;
	t_count_inst	count_inst;
	t_count_inst	tmp_count;
	t_list			*tmp;

	count_inst.total_intruct = -1;
	sorted_list = find_bigger_sorted(master_stack->bg_sa);
	//ft_printf("%d", size_sorted_list(sorted_list));
	if (size_sorted_list(sorted_list) < 4)
	{
		clean_for_three(master_stack);
		sort_small(master_stack);
	}
	else
	{
		ft_printf("la");
		clean_sorted_list(master_stack, sorted_list, 0);
	}
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
		/*ft_printf("a:[%d]\n", count_inst.count_instruct_a);
		ft_printf("b:[%d]\n", count_inst.count_instruct_b);
		ft_printf("total:[%d]\n", count_inst.total_intruct);*/
		//process_sort_big(master_stack, count_inst);
	}
	/*while (!list_sorted(master_stack->bg_sa))
		rotate(master_stack, 'a');*/
}