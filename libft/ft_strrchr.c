/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:00:15 by genouf            #+#    #+#             */
/*   Updated: 2022/04/04 18:54:58 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > -1)
	{
		if (s[i] == (unsigned char)c)
		{
			s += i;
			return ((char *)s);
		}
		i--;
	}
	return (NULL);
}

/*int	main(void)
{
	char	str[] = "Emmanuael";

	printf("%s", ft_strrchr(str, 'a'));
}*/
