/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 02:58:12 by genouf            #+#    #+#             */
/*   Updated: 2022/06/11 16:28:48 by genouf           ###   ########.fr       */
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

void	begin_init(int argc, t_m_list *master_stack)
{
	master_stack->bg_sa = NULL;
	master_stack->bg_sb = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
}

void	clean_argv(char **tmp, int j)
{
	while (j > -1)
	{
		free(tmp[j]);
		j--;
	}
	free(tmp);
}

int	check_m_zero(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		while (str[i])
		{
			if (str[i] != '0')
				return (0);
			i++;
		}
	}
	else
		return (0);
	return (1);
}
