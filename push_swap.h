/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:25:01 by genouf            #+#    #+#             */
/*   Updated: 2022/05/24 17:01:25 by genouf           ###   ########.fr       */
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
}					t_s_l;
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
	int	initialized;
	int	total_intruct;
	int	count_instruct_a;
	int	count_instruct_b;
}					t_c_i;

/* PROTOTYPES */
/*		ARG_CHECK		*/
int		checker_argv(int argc, char **argv, t_list **begin_list, int i);
/*		INSTRUCTIONS		*/	
void	swap(t_m_list *master_stack, char stack_name);
void	rotate(t_m_list *master_stack, char stack_name);
void	reverse_rotate(t_m_list *master_stack, char stack_name);
void	double_action(t_m_list *master_stack,
			void (*f)(t_m_list *master_stack, char stack_name), char a_name);
/*		INSTRUCTIONS_BIS		*/
void	push_a(t_list **begin_list_a, t_list **begin_list_b);
void	push_b(t_list **begin_list_a, t_list **begin_list_b);
/*		ADD_INDEX		*/
void	add_index(t_list **begin_list);
/*		SORT_THIS		*/
int		list_sorted(t_list *begin_list);
void	clean_for_three(t_m_list *master_stack);
void	sort_small(t_m_list *master_stack);
/*		FIND_BIGGER_SORTED		*/
t_s_l	find_bigger_sorted(t_list *begin_list);
void	clean_sorted_list(t_m_list *master_stack,
			t_s_l sorted_list, int count);
int		size_sorted_list(t_s_l sorted_list);
/*		SORT_THIS_BIG		*/
t_c_i	find_next_index(t_list *b_element, t_m_list *master_stack,
			int size_b, int size_a);
void	set_total_instruct(t_c_i *count_inst);
void	push_sort(t_m_list *master_stack);
/*		SORT_THIS_BIG_DO		*/
void	sort_big(t_m_list *master_stack);
void	process_sort_same_minus(t_m_list	*master_stack,
			t_c_i count_inst, char *tab_info);
void	action_same(t_m_list *master_stack, int tmp, t_c_i count_inst,
			char *tab_info);
void	process_action_same(t_m_list *master_stack, int tmp, int count_inst_min,
			char stack_info);
void	process_sort_different(t_m_list *master_stack, t_c_i count_inst,
			char stack);
void	process_sort_same(t_m_list *master_stack, t_c_i count_inst);
int		calcul_inst_a(t_m_list *master_stack, t_list *b_elem);
char	**begin_init(char **argv, int *i, int argc, t_m_list *master_stack);

#endif
