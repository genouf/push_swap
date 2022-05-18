#include "push_swap.h"
#include <stdio.h>

void	ft_lstprintsorted(t_sortlist *sorted_list)
{
	t_list	*tmp;

	tmp = sorted_list->first;
	while (tmp != sorted_list->last->next)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}

t_sortlist *find_bigger_sorted(t_list *begin_list)
{
	
}

int	main(int argc, char **argv)
{
	t_m_list	master_stack;
	int		i;
	
	argv = begin_init(argv, &i, argc, &master_stack);
	if (!checker_argv(argc, argv, &(master_stack.bg_sa), i))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	add_index(&master_stack.bg_sa);
}