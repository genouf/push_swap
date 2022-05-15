/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:59:23 by genouf            #+#    #+#             */
/*   Updated: 2022/04/04 23:45:05 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*c;
	unsigned char	*p;
	unsigned char	*tmp;
	size_t			i;

	c = (unsigned char *)src;
	p = (unsigned char *)dst;
	tmp = (unsigned char *)malloc(len);
	if (tmp == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		tmp[i] = c[i];
	i = 0;
	while (len > 0)
	{
		*p = tmp[i];
		p++;
		i++;
		len--;
	}
	free(tmp);
	return (dst);
}

/*int main()
{
    char str[8] = "bonjour";
    
    ft_memmove(str + 1, str, 6);
    printf("the result of ft_memcpy is %s\n", str);
    return (0);
}*/