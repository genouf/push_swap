/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:25:01 by genouf            #+#    #+#             */
/*   Updated: 2022/05/18 18:20:20 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/* TYPEDEF */
typedef struct s_m_list
{
	struct s_list	*bg_sa;
	struct s_list	*bg_sb;
}					t_m_list;

int		checker_argv(int argc, char **argv, t_list **begin_list, int i);
void	swap(t_list **begin_list, char stack_name);
void	rotate(t_list **begin_list, char stack_name);
void	reverse_rotate(t_list **begin_list, char stack_name);
void	push_a(t_list **begin_list_a, t_list **begin_list_b);
void	push_b(t_list **begin_list_a, t_list **begin_list_b);
void	double_action(t_m_list *master_stack, void (*f)(t_list **begin_list),
			char a_name);
void	add_index(t_list **begin_list);
void	sort_min(t_m_list *master_stack);

#endif
