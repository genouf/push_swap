#include "push_swap.h"
#include <stdio.h>

void	ft_lstprintsorted(t_sortlist sorted_list)
{
	t_list	*tmp;

	tmp = sorted_list.first;
	while (tmp && tmp != sorted_list.last->next)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
}

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

t_tosort	init_find_bigger(t_list *begin_list, t_sortlist *sorted_list)
{
	t_tosort	tosort;

	sorted_list->first = NULL;
	sorted_list->last = NULL;
	tosort.tmp_first = begin_list;
	tosort.precedent = begin_list;
	tosort.max_count = 0;
	tosort.count = 0;
	tosort.tmp = begin_list->content;
	return (tosort);
}

void	set_sorted_list(t_sortlist *sorted_list, t_tosort *tosort)
{
	if (tosort->count > tosort->max_count)
	{
		tosort->max_count = tosort->count;
		sorted_list->first = tosort->tmp_first;
		sorted_list->last = tosort->precedent;
	}
}

t_sortlist find_bigger_sorted(t_list *begin_list)
{
	t_sortlist	sorted_list;
	t_tosort	tosort;

	tosort = init_find_bigger(begin_list, &sorted_list);
	begin_list = begin_list->next;
	while (begin_list)
	{
		if (tosort.tmp < begin_list->content)
			tosort.count++;
		else
		{
			set_sorted_list(&sorted_list, &tosort);	
			tosort.count = 0;
			tosort.tmp_first = begin_list;
		}
		tosort.precedent = begin_list;
		tosort.tmp = begin_list->content;
		begin_list = begin_list->next;
	}
	set_sorted_list(&sorted_list, &tosort);	
	return (sorted_list);
}

int	main(int argc, char **argv)
{
	t_m_list	master_stack;
	t_sortlist	sorted_list;
	int		i;
	
	argv = begin_init(argv, &i, argc, &master_stack);
	if (!checker_argv(argc, argv, &(master_stack.bg_sa), i))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	add_index(&master_stack.bg_sa);
	sorted_list = find_bigger_sorted(master_stack.bg_sa);
	ft_lstprintsorted(sorted_list);
	return (0);
}