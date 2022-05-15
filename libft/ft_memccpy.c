/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:57:29 by genouf            #+#    #+#             */
/*   Updated: 2022/03/31 16:15:46 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*copy;
	unsigned char	*p;

	copy = (unsigned char *)src;
	p = (unsigned char *)dst;
	while (n > 0)
	{
		*p = *copy;
		p++;
		if (*copy == c)
			return (p);
		copy++;
		n--;
	}
	return (NULL);
}

/*int main()
{
    char src[8] = "bonjour";
    char dst[35] = "salut a tous lerptizamismdr";
    char *result;
    
    printf("the src string is : %s\n", src);
    printf("the dst string is : %s\n", dst);
    result = ft_memccpy(dst, src, 'j', 7);
    printf("the new dst string is : %s\n", dst);    
    printf("the result of ft_memccpy is : %s\n", result);
    return (0);
}*/