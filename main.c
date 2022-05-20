/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:30:34 by genouf            #+#    #+#             */
/*   Updated: 2022/05/20 13:30:09 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_lstprint(t_list *begin_list)
{
	while (begin_list)
	{
		printf("%d  %d\n", begin_list->content, begin_list->index);
		begin_list = begin_list->next;
	}
}

char	**begin_init(char **argv, int *i, int argc, t_m_list *master_stack)
{
	master_stack->bg_sa = NULL;
	master_stack->bg_sb = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		*i = 0;
		argv = ft_split(argv[1], ' ');
	}
	else
		*i = 1;
	return (argv);
}

int main(int argc, char **argv)
{
	t_m_list	master_stack;
	//t_sortlist	sorted_list;
	t_count_inst	count_inst;
	int		i;
	
	argv = begin_init(argv, &i, argc, &master_stack);
	if (!checker_argv(argc, argv, &(master_stack.bg_sa), i))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	add_index(&master_stack.bg_sa);
	//sorted_list = find_bigger_sorted(master_stack.bg_sa);
	printf("STACK A:\n");
	ft_lstprint(master_stack.bg_sa);
	printf("STACK B:\n");	
	ft_lstprint(master_stack.bg_sb);
	push_b(&(master_stack.bg_sa), &(master_stack.bg_sb));
	push_b(&(master_stack.bg_sa), &(master_stack.bg_sb));
	push_b(&(master_stack.bg_sa), &(master_stack.bg_sb));
	printf("\n ------ \n\n");
	printf("STACK A:\n");
	ft_lstprint(master_stack.bg_sa);
	printf("STACK B:\n");	
	ft_lstprint(master_stack.bg_sb);
	//count_inst = find_next_index(master_stack.bg_sb, &master_stack, ft_lstsize(master_stack.bg_sa), ft_lstsize(master_stack.bg_sa));
	//printf("\n[%d]", count_inst.count_instruct_a);
	//printf("\n[%d]", count_inst.count_instruct_b);
	push_a(&(master_stack.bg_sa), &(master_stack.bg_sb));
	push_a(&(master_stack.bg_sa), &(master_stack.bg_sb));
	printf("\n ------ \n\n");
	printf("STACK A:\n");
	ft_lstprint(master_stack.bg_sa);
	printf("STACK B:\n");	
	ft_lstprint(master_stack.bg_sb);
	count_inst = find_next_index(master_stack.bg_sb, &master_stack, ft_lstsize(master_stack.bg_sa), ft_lstsize(master_stack.bg_sa));
	printf("\n[%d]", count_inst.count_instruct_a);
	printf("\n[%d]", count_inst.count_instruct_b);
	//clean_sorted_list(&master_stack, sorted_list, 0);
	//sort_small(&(master_stack.bg_sa));
	//clean_for_three(&master_stack);
	//printf("\n ------ \n\n");
	//printf("STACK A:\n");
	//ft_lstprint(master_stack.bg_sa);
	//printf("STACK B:\n");	
	//ft_lstprint(master_stack.bg_sb);
	//printf("NB SORTED:%d", size_sorted_list(sorted_list));
	return (0);
}

