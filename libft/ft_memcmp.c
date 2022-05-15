/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:35:55 by genouf            #+#    #+#             */
/*   Updated: 2022/04/04 23:14:54 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	if (n == 0)
		return (0);
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	i = 0;
	while (s1c[i] == s2c[i] && i < n - 1)
		i++;
	if (s1c[i] > s2c[i])
		return (1);
	else if (s1c[i] < s2c[i])
		return (-1);
	else
		return (0);
}

/*int	main(void)
{
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};

	printf("%d\n", memcmp(s2, s3, 4));
	printf("%d", ft_memcmp(s2, s3, 4));
	
}*/