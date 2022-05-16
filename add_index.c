/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remote.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 04:45:07 by genouf            #+#    #+#             */
/*   Updated: 2022/05/16 21:30:44 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int *tab_transform, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab_transform[i] > tab_transform[j])
			{
				tmp = tab_transform[i];
				tab_transform[i] = tab_transform[j];
				tab_transform[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	init_tab(t_list **begin_list, int **tab_transform, int size)
{
	t_list	*tmp;
	int		i;

	*tab_transform = (int *)malloc(sizeof(int) * size);
	if (tab_transform == NULL)
		return ;
	tmp = *begin_list;
	i = 0;
	while (tmp)
	{
		(*tab_transform)[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
}

void	set_in_list(t_list **begin_list, int content, int index)
{
	t_list	*tmp;

	tmp = *begin_list;
	while (tmp)
	{
		if (tmp->content == content)
		{
			tmp->index = index;
			return ;
		}
		tmp = tmp->next;
	}	
}

int	add_index(t_list **begin_list)
{
	int	*tab_transform;
	int	size;
	int	i;

	size = ft_lstsize(*begin_list);
	init_tab(begin_list, &tab_transform, size);
	if (tab_transform == NULL)
	{
		ft_lstclear(begin_list);
		return (0);
	}
	sort_tab(tab_transform, size);
	i = 0;
	while (i < size)
	{
		set_in_list(begin_list, tab_transform[i], i);
		i++;
	}
	free(tab_transform);
	return (1);
}
