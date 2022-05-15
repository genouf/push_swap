/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:16:19 by genouf            #+#    #+#             */
/*   Updated: 2022/05/12 13:26:24 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long nb, int *count)
{
	int		i;
	char	buff[12];

	if (nb == 0)
	{
		*count += ft_putchar('0');
		return ;
	}	
	i = 0;
	while (i < 8 && nb > 0)
	{
		if (nb % 16 >= 10)
			buff[i] = 'a' + nb % 16 % 10;
		else
			buff[i] = '0' + nb % 16;
		i++;
		nb /= 16;
	}
	while (--i > -1)
		*count += ft_putchar(buff[i]);
}

void	ft_puthex_maj(unsigned long nb, int *count)
{
	int		i;
	char	buff[12];

	if (nb == 0)
	{
		*count += ft_putchar('0');
		return ;
	}
	i = 0;
	while (i < 8 && nb > 0)
	{
		if (nb % 16 >= 10)
			buff[i] = 'A' + nb % 16 % 10;
		else
			buff[i] = '0' + nb % 16;
		i++;
		nb /= 16;
	}
	while (--i > -1)
		*count += ft_putchar(buff[i]);
}
