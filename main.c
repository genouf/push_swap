/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:30:34 by genouf            #+#    #+#             */
/*   Updated: 2022/05/16 20:21:32 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_lstprint(t_list *begin_list)
{
	while (begin_list)
	{
		ft_printf("%d  %d\n", begin_list->content, begin_list->index);
		begin_list = begin_list->next;
	}
}

int main(int argc, char **argv)
{
	m_list	master_stack;

	if (argc == 1)
		return (1);
	master_stack.bg_sa = NULL;
	master_stack.bg_sb = NULL;
	if (!checker_argv(argc, argv, &(master_stack.bg_sa)))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!add_index(&master_stack.bg_sa))
		return (1);
	ft_printf("STACK A:\n");
	ft_lstprint(master_stack.bg_sa);
	//ft_printf("STACK B:\n");	
	//ft_lstprint(master_stack.bg_sb);
	sort_min(&master_stack);
	ft_printf("\n ------ \n");
	ft_printf("STACK A:\n");
	ft_lstprint(master_stack.bg_sa);

	return (0);
}