/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 08:56:03 by genouf            #+#    #+#             */
/*   Updated: 2022/04/05 01:48:13 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinbase(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	find_len(char const *s1, char const *set)
{
	int	i;
	int	size;

	size = ft_strlen(s1);
	while (size && ft_isinbase(set, s1[size - 1]))
		size--;
	i = 0;
	while (s1[i] && size && ft_isinbase(set, s1[i]))
	{
		size--;
		i++;
	}
	return (size);
}	

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		len_result;
	int		i;
	int		j;

	len_result = find_len(s1, set);
	result = (char *)malloc(sizeof(char) * (len_result + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && ft_isinbase(set, s1[i]))
		i++;
	j = 0;
	while (s1[i] && j < len_result)
	{
		result[j] = s1[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char	*s;

// 	s = ft_strtrim("", "123");
// 	printf("%s", s);
// }