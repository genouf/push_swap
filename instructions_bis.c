/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 02:58:12 by genouf            #+#    #+#             */
/*   Updated: 2022/05/16 02:58:43 by genouf           ###   ########.fr       */
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
}