/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:47:26 by genouf            #+#    #+#             */
/*   Updated: 2022/04/17 11:14:26 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	i = 0;
	if (size < len)
		len = size;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	if (start < (unsigned int)size)
	{
		while (i < len)
		{
			result[i] = s[start];
			i++;
			start++;
		}
	}
	result[i] = '\0';
	return (result);
}

/*int	main(void)
{
	char	*result;

	result = ft_substr("tripouille", 9, 100);
	printf("%s\n", result);
}*/