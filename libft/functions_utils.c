/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:59:37 by genouf            #+#    #+#             */
/*   Updated: 2022/05/12 13:26:35 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	while (s && s[i])
	{
		*count += ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int n, int *count)
{
	long	i;

	i = n;
	if (i < 0)
	{
		*count += ft_putchar('-');
		i = -i;
	}
	if (i > 9)
		ft_putnbr(i / 10, count);
	*count += ft_putchar('0' + (i % 10));
}

void	ft_putnbr_uns(unsigned int n, int *count)
{
	if (n > 9)
		ft_putnbr_uns(n / 10, count);
	*count += ft_putchar('0' + (n % 10));
}

void	ft_putaddr(unsigned long long addr, int *count)
{
	int		i;
	char	buff[20];

	if (addr == 0)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	i = 0;
	while (addr)
	{
		if (addr % 16 >= 10)
			buff[i] = 'a' + addr % 16 % 10;
		else
			buff[i] = '0' + addr % 16;
		i++;
		addr /= 16;
	}
	write(1, "0x", 2);
	*count += 2;
	while (--i > -1)
		*count += ft_putchar(buff[i]);
}
