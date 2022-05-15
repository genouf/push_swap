/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:12:19 by genouf            #+#    #+#             */
/*   Updated: 2022/05/11 12:45:56 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
	return (count);
}

char	**free_all(char **result, int x)
{
	while (x > -1)
		free(result[x--]);
	free(result);
	return (NULL);
}

char	*split_process(char const *s, char c, int *i)
{
	int		j;
	int		count;
	char	*result;

	count = 0;
	j = *i;
	while (s[j] != c && s[j])
	{
		count++;
		j++;
	}
	result = (char *)malloc(sizeof(char) * (count + 1));
	if (result == NULL)
		return (NULL);
	(*i)--;
	j = -1;
	while (s[++(*i)] != c && s[*i])
		result[++j] = s[*i];
	result[j + 1] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		x;

	i = 0;
	x = -1;
	result = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (result == NULL)
		return (free_all(result, x));
	while (s[i])
	{
		if (s[i] != c)
		{
			result[++x] = split_process(s, c, &i);
			if (result[x] == NULL)
				return (free_all(result, x));
		}
		else
			i++;
	}
	result[x + 1] = 0;
	return (result);
}

// int	main(void)
// {
// 	char	str[] = ("--1-2--3---4----5-----42");
// 	char	**result;
// 	int		i;

// 	result = ft_split(str, '-');
// 	i = 0;
// 	while (i < 6)
// 	{
// 		printf("%s\n", result[i]);
// 		i++;
// 	}
// 	//printf("%d", count_word(str, ' '));
// 	//printf("%d", count_size(str, ' ', 7));
// 	return (0);
// }