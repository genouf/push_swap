/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:30:34 by genouf            #+#    #+#             */
/*   Updated: 2022/06/08 11:25:40 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	redirect(t_m_list *master_stack)
{
	int	i;

	i = ft_lstsize(master_stack->bg_sa);
	if (i == 2)
	{
		if (!list_sorted(master_stack->bg_sa))
			swap(master_stack, 'a');
	}
	else if (i == 3)
		sort_small(master_stack);
	else if (i > 3)
		sort_big(master_stack);
}

int	main(int argc, char **argv)
{
	t_m_list	master_stack;

	begin_init(argc, &master_stack);
	if (!checker_argv(argc, argv, &(master_stack.bg_sa), 1))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	add_index(&master_stack.bg_sa);
	redirect(&master_stack);
	ft_lstclear(&(master_stack.bg_sa));
	return (0);
}
