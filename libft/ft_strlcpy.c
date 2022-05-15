/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:59:48 by genouf            #+#    #+#             */
/*   Updated: 2022/04/04 19:15:54 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize != 0)
	{
		i = 0;
		while (i + 1 < dstsize && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*int main()
{
    char src[8] = "bonjour";
    char dst[10] = "AAAAAAAAA";

    size_t result = ft_strlcpy(dst, src, 1);
    printf("the result of ft_strlcpy is %zu\n", result);
    printf("the copy of ft_strlcpy is %s\n", &dst[1]);
    return (0);
}*/
