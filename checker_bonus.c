/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:33:45 by genouf            #+#    #+#             */
/*   Updated: 2022/06/14 17:32:19 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"

void	check_end(t_m_list *master_stack)
{
	if (list_sorted(master_stack->bg_sa) && master_stack->bg_sb == NULL)
	{
		write(1, "OK\n", 3);
		ft_lstclear(&(master_stack->bg_sa));
	}
	else
	{
		write(1, "KO\n", 3);
		ft_lstclear(&(master_stack->bg_sa));
		if (master_stack->bg_sb != NULL)
			ft_lstclear(&(master_stack->bg_sb));
	}
}

void	do_instructions_follow(char *instruct, t_m_list *master_stack)
{
	if (ft_memcmp("r", instruct, 1) == 0 && instruct[1] != 'r')
	{
		if (instruct[1] == 'a')
			rotate_c(master_stack, 'a');
		else if (instruct[1] == 'b')
			rotate_c(master_stack, 'b');
		else
			print_error(instruct, master_stack);
	}
	else if (ft_memcmp("rr", instruct, 2) == 0)
	{
		if (instruct[2] == 'a')
			reverse_rotate_c(master_stack, 'a');
		else if (instruct[2] == 'b')
			reverse_rotate_c(master_stack, 'b');
		else if (instruct[2] == '\n')
			double_action_c(master_stack, &rotate);
		else if (instruct[2] == 'r')
			double_action_c(master_stack, &reverse_rotate);
		else
			print_error(instruct, master_stack);
	}
	else
		print_error(instruct, master_stack);
}

void	do_instructions(char *instruct, t_m_list *master_stack)
{
	if (ft_memcmp("pa", instruct, 2) == 0)
		push_a_c(&(master_stack->bg_sa), &(master_stack->bg_sb));
	else if (ft_memcmp("pb", instruct, 2) == 0)
		push_b_c(&(master_stack->bg_sa), &(master_stack->bg_sb));
	else if (ft_memcmp("s", instruct, 1) == 0)
	{
		if (instruct[1] == 'a')
			swap_c(master_stack, 'a');
		else if (instruct[1] == 'b')
			swap_c(master_stack, 'b');
		else if (instruct[1] == 's')
			double_action_c(master_stack, &swap);
		else
			print_error(instruct, master_stack);
	}
	else
		do_instructions_follow(instruct, master_stack);
}

void	sort(t_m_list *master_stack)
{
	char	*instruct;

	instruct = get_next_line(0);
	while (instruct != NULL)
	{
		if (instruct != NULL)
			do_instructions(instruct, master_stack);
		free(instruct);
		instruct = get_next_line(0);
	}
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
	if (master_stack.bg_sa == NULL)
		exit(EXIT_FAILURE);
	sort(&master_stack);
	check_end(&master_stack);
	return (0);
}
