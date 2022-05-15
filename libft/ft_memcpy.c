/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:59:17 by genouf            #+#    #+#             */
/*   Updated: 2022/03/31 15:59:19 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c;
	unsigned char	*p;

	c = (unsigned char *)src;
	p = (unsigned char *)dst;
	while (n > 0)
	{
		*p = *c;
		p++;
		c++;
		n--;
	}
	return (dst);
}

/*int main()
{
    char str[8] = "bonjour";
    
    ft_memcpy(str + 1, str, 6);
    printf("the result of ft_memcpy is %s\n", str);
    return (0);
}*/