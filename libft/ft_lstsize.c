/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:02:54 by genouf            #+#    #+#             */
/*   Updated: 2022/04/05 17:32:26 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*tmp;

	if (!lst)
		return (0);
	count = 0;
	tmp = lst;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

/*int	main(void)
{
	t_list **pile;
	t_list *elem1;
	t_list *elem2;
	t_list *elem3;
	t_list *new_one;
	t_list *tmp;

	elem1 = ft_lstnew("G");
	elem2 = ft_lstnew("a");
	elem3 = ft_lstnew("b");
	pile = &elem1;
	elem1->next = elem2;
	elem2->next = elem3;

	new_one = ft_lstnew("A");
	ft_lstadd_front(pile, new_one);
	tmp = elem1;
	while (tmp)
	{
		printf("%s", (char *)tmp->content);
		tmp = tmp->next;
	}
	printf("%d", ft_lstsize(*pile));
}*/