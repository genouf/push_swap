/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:45:43 by genouf            #+#    #+#             */
/*   Updated: 2022/04/04 23:14:28 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void iter(unsigned int i, char * s) 
{
	*s += i;
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (*s)
	{
		(*f)(i, s);
		s++;
		i++;
	}	
}

/*int	main(void)
{
	char s[] = "0";
	ft_striteri(s, iter);
	printf("%s", s);
}*/