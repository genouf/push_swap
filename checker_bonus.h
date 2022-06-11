/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:44:39 by genouf            #+#    #+#             */
/*   Updated: 2022/06/11 19:17:28 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

/* INCLUDE */
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "push_swap.h"

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_substr_gnl(char *s, unsigned int start, char *save);
void	ft_splitbuff_gnl(char **buff, char **result, int id_line);
char	*ft_subuff_gnl(char *buff, int id_line);
void	*ft_calloc_gnl(size_t count, size_t size);
size_t	ft_strlcpy_gnl(char *dst, char *src, size_t dstsize);
void	swap_c(t_m_list *master_stack, char stack_name);
void	rotate_c(t_m_list *master_stack, char stack_name);
void	reverse_rotate_c(t_m_list *master_stack, char stack_name);
void	double_action_c(t_m_list *master_stack, void (*f)
			(t_m_list *master_stack, char stack_name));
void	push_a_c(t_list **begin_list_a, t_list **begin_list_b);
void	push_b_c(t_list **begin_list_a, t_list **begin_list_b);
void	print_error(char *instruct, t_m_list *master_stack);

#endif
