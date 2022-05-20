/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:25:01 by genouf            #+#    #+#             */
/*   Updated: 2022/05/20 05:02:48 by genouf           ###   ########.fr       */
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
typedef struct s_sortlist
{
	struct s_list	*first;
	struct s_list	*last;
}					t_sortlist;
typedef struct s_tosort
{
	struct s_list	*tmp_first;
	struct s_list	*precedent;
	int				max_count;
	int				count;
	int				tmp;
}					t_tosort;
typedef struct s_count_inst
{
	int	count_instruct_a;
	int	count_instruct_b;
}					t_count_inst;

/* PROTOTYPES */
int		checker_argv(int argc, char **argv, t_list **begin_list, int i);
void	swap(t_list **begin_list, char stack_name);
void	rotate(t_list **begin_list, char stack_name);
void	reverse_rotate(t_list **begin_list, char stack_name);
void	push_a(t_list **begin_list_a, t_list **begin_list_b);
void	push_b(t_list **begin_list_a, t_list **begin_list_b);
void	double_action(t_m_list *master_stack, void (*f)(t_list **begin_list),
			char a_name);
void	add_index(t_list **begin_list);
void	sort_small(t_list **begin_list);
char	**begin_init(char **argv, int *i, int argc, t_m_list *master_stack);
t_sortlist find_bigger_sorted(t_list *begin_list);
void	clean_sorted_list(t_m_list *master_stack, t_sortlist sorted_list, int count);
int		size_sorted_list(t_sortlist sorted_list);
void	clean_for_three(t_m_list *master_stack);
/*		SORT_THIS_BIG		*/
t_count_inst	find_next_index(t_list *b_element, t_m_list *master_stack, int size_b, int size_a);

#endif
