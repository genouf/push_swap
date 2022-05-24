/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 12:30:34 by genouf            #+#    #+#             */
/*   Updated: 2022/05/24 11:14:04 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_lstprint(t_list *begin_list)
{
	while (begin_list)
	{
		printf("%d  %d\n", begin_list->content, begin_list->index);
		begin_list = begin_list->next;
	}
}*/

char	**begin_init(char **argv, int *i, int argc, t_m_list *master_stack)
{
	master_stack->bg_sa = NULL;
	master_stack->bg_sb = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		*i = 0;
		argv = ft_split(argv[1], ' ');
	}
	else
		*i = 1;
	return (argv);
}

int	main(int argc, char **argv)
{
	t_m_list	master_stack;
	int			i;

	argv = begin_init(argv, &i, argc, &master_stack);
	if (!checker_argv(argc, argv, &(master_stack.bg_sa), i))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (i == 0)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	add_index(&master_stack.bg_sa);
	sort_big(&master_stack);
	ft_lstclear(&(master_stack.bg_sa));
	return (0);
}
