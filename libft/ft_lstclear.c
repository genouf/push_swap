/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:33:12 by genouf            #+#    #+#             */
/*   Updated: 2022/05/16 21:57:34 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(current);
		current = *lst;
	}
}
