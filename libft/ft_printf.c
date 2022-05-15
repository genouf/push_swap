/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:52:01 by genouf            #+#    #+#             */
/*   Updated: 2022/05/14 12:13:22 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_result(char c, va_list args, int *count)
{
	if (c == 'c')
		*count += ft_putchar(va_arg(args, int));
	else if (c == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (c == 'p')
		ft_putaddr((unsigned long long)va_arg(args, char *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (c == 'u')
		ft_putnbr_uns(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_puthex((unsigned long)va_arg(args, unsigned int), count);
	else if (c == 'X')
		ft_puthex_maj((unsigned long)va_arg(args, unsigned int), count);
	else if (c == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	else
		return (0);
	return (1);
}

int	ft_printf(char const *s, ...)
{
	size_t		i;
	int			count;
	va_list		args;

	i = 0;
	count = 0;
	va_start(args, s);
	while (i < ft_strlen(s))
	{
		if (s[i] == '%')
		{
			if (print_result(s[i + 1], args, &count))
				i += 2;
			else
				i++;
		}		
		else
		{
			count += ft_putchar(s[i]);
			i++;
		}		
	}
	va_end(args);
	return (count);
}
