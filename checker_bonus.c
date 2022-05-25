/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:33:45 by genouf            #+#    #+#             */
/*   Updated: 2022/05/25 13:26:34 by genouf           ###   ########.fr       */
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

int	do_instructions_follow(char *instruct, t_m_list *master_stack)
{
	if (ft_memcmp("rr", instruct, 2) == 0)
	{
		if(instruct[2] == 'a')
			reverse_rotate(master_stack, 'a');
		else if (instruct[2] == 'b')
			reverse_rotate(master_stack, 'b');
		else if (instruct[2] == '\n')
			double_action(master_stack, &rotate, 'r');
		else if (instruct[2] == 'r')
			double_action(master_stack, &reverse_rotate, 'l');
		return (1);
	}
	return (0);
}

void	do_instructions(char *instruct, t_m_list *master_stack)
{
	if (ft_memcmp("pa", instruct, 2) == 0)
		push_a(&(master_stack->bg_sa), &(master_stack->bg_sb));
	else if (ft_memcmp("pb", instruct, 2) == 0)
		push_b(&(master_stack->bg_sa), &(master_stack->bg_sb));
	else if (ft_memcmp("r", instruct, 1) == 0 && instruct[1] != 'r')
	{
		if(instruct[1] == 'a')
			rotate(master_stack, 'a');
		else if (instruct[1] == 'b')
			rotate(master_stack, 'b');
	}
	else if (ft_memcmp("s", instruct, 1) == 0)
	{
		if(instruct[1] == 'a')
			swap(master_stack, 'a');
		else if (instruct[1] == 'b')
			swap(master_stack, 'b');
		else if (instruct[1] == 's')
			double_action(master_stack, &swap, 's');
	}
	else 
	{
		if (do_instructions_follow(instruct, master_stack) == 0)
			write(1, "Error\n", 6);
	}
}

void	sort(t_m_list *master_stack)
{
	char	*instruct;

	instruct = get_next_line(0);
	while (instruct != NULL)
	{
		if (instruct != NULL)
			do_instructions(instruct, master_stack);
		instruct = get_next_line(0);
	}
}

int	main(int argc, char ** argv)
{
	t_m_list	master_stack;
	int			i;

	argv = begin_init(argv, &i, argc, &master_stack);
	if (!checker_argv(argc, argv, &(master_stack.bg_sa), i))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (i == 0)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	sort(&master_stack);
	check_end(&master_stack);
	return (0);
}