/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:02:42 by genouf            #+#    #+#             */
/*   Updated: 2022/04/05 21:00:22 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*int	main(void)
{
	t_list **pile;
	t_list *elem1;
	t_list *elem2;
	t_list *elem3;
	t_list *tmp;

	elem1 = ft_lstnew("G");
	elem2 = ft_lstnew("a");
	elem3 = ft_lstnew("b");
	pile = &elem1;
	elem1->next = elem2;
	elem2->next = elem3;

	tmp = elem1;
	while (tmp)
	{
		//printf("%s", (char *)tmp->content);
		tmp = tmp->next;
	}
	tmp = ft_lstlast(*pile);
	printf("%s", (char *)tmp->content);
}*/