/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:52:56 by genouf            #+#    #+#             */
/*   Updated: 2022/05/12 00:40:28 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size_number(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*create_number(char *result, int n, long tmp)
{
	int	j;
	int	size_nb;

	size_nb = size_number(tmp);
	j = 0;
	while (size_nb > 0)
	{
		result[j] = tmp % 10 + 48;
		j++;
		tmp /= 10;
		size_nb--;
	}
	if (n < 0)
	{
		result[j] = '-';
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	tmp;
	int		i;

	tmp = n;
	i = size_number(tmp) + 1;
	if (tmp < 0)
	{
		tmp = -tmp;
		i += 1;
	}
	result = (char *)malloc(sizeof(char) * i);
	if (result == NULL)
		return (NULL);
	if (tmp == 0)
	{
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	return (ft_strrev(create_number(result, n, tmp)));
}

/*int	main(void)
{
	printf("%s", ft_itoa(213));
	return (0);
}*/