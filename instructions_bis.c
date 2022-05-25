/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 02:58:12 by genouf            #+#    #+#             */
/*   Updated: 2022/05/25 12:26:07 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list **begin_list_a, t_list **begin_list_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*begin_list_b))
		return ;
	tmp = (*begin_list_b)->next;
	tmp2 = *begin_list_a;
	*begin_list_a = *begin_list_b;
	(*begin_list_a)->next = tmp2;
	*begin_list_b = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_list **begin_list_a, t_list **begin_list_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*begin_list_a))
		return ;
	tmp = (*begin_list_a)->next;
	tmp2 = *begin_list_b;
	*begin_list_b = *begin_list_a;
	(*begin_list_b)->next = tmp2;
	*begin_list_a = tmp;
	write(1, "pb\n", 3);
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
