/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:25:01 by genouf            #+#    #+#             */
/*   Updated: 2022/05/16 09:21:11 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/* TYPEDEF */
typedef struct m_list
{
	struct s_list	*bg_sa;
	struct s_list	*bg_sb;
}					m_list;

int		checker_argv(int argc, char **argv, t_list **begin_list);
void	swap(t_list **begin_list);
void	rotate(t_list **begin_list);
void	reverse_rotate(t_list **begin_list);
void	push_a(t_list **begin_list_a, t_list **begin_list_b);
void	push_b(t_list **begin_list_a, t_list **begin_list_b);
void	double_action(m_list *master_stack, void (*f)(t_list **begin_list));
int		add_index(t_list **begin_list);

#endif
