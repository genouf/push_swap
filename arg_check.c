/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:16:12 by genouf            #+#    #+#             */
/*   Updated: 2022/06/14 19:35:17 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker_digit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	checker_integer(char *str, long number, char *tmp, char *tmp2)
{
	if (str[0] == '-')
	{
		if (ft_strncmp(str, tmp, 1) != 0)
		{
			free(tmp);
			return (0);
		}
		str++;
		tmp2 = tmp;
		tmp = ft_strdup(tmp + 1);
		free(tmp2);
	}
	else if (str[0] == '+')
		str++;
	while (*str == '0' && str[1] != '\0')
		str++;
	if (ft_strncmp(str, tmp, 25) != 0)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (1);
}

int	checker_list(int number, t_list **begin_list)
{
	t_list	*tmp;

	if (!begin_list)
		return (1);
	tmp = *begin_list;
	while (tmp)
	{
		if (tmp->content == number)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	checker_entry(char *str, t_list **begin_list, int *content)
{
	long	number;

	if (!checker_digit(str))
		return (0);
	number = ft_atoi(str);
	if (!checker_integer(str, number, ft_itoa((int)number), NULL)
		&& !check_m_zero(str))
		return (0);
	if (!checker_list((int)number, begin_list))
		return (0);
	*content = (int)number;
	return (1);
}

int	checker_argv(int argc, char **argv, t_list **begin_list, int i)
{
	t_check_a	check;

	check.content = 0;
	while (i < argc)
	{
		if (argv[i][0] == '\0' || (argv[i][0] == ' ' && argv[i][1] == '\0'))
			return (0);
		check.tmp = ft_split(argv[i], ' ');
		check.j = 0;
		while (check.tmp[check.j])
		{
			if (!checker_entry(check.tmp[check.j], begin_list, &check.content))
			{
				ft_lstclear(begin_list);
				clean_argv(check.tmp, check.j);
				return (0);
			}
			ft_lstadd_back(begin_list, ft_lstnew(check.content));
			check.j++;
		}
		clean_argv(check.tmp, check.j - 1);
		i++;
	}
	return (1);
}
