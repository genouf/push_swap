/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:59:43 by genouf            #+#    #+#             */
/*   Updated: 2022/04/04 20:10:34 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i])
		i++;
	if (i > dstsize)
		return (ft_strlen(src) + dstsize);
	j = 0;
	while (src[j] && (i + j + 1 < dstsize))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}

/*int	main(void)
{
	char * src = (char *)"AAAAAAAAA";
    char dst[30] = {0}; 
    memset (dst, 'B', 4);

    
    size_t result = ft_strlcat(dst, src, 6);
    printf("ft_strlcat returns %zu\n", result);
    printf("the resulting string of ft_strlcat is %s\n", dst);
	memset(dst, 0, 30);
    memset (dst, 'B', 4);
    result = strlcat(dst, src, 6);
    printf("strlcat returns %zu\n", result);
    printf("the resulting string of strlcat is %s\n", dst);

    return (0);
}*/
