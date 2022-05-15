/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:00:27 by genouf            #+#    #+#             */
/*   Updated: 2022/03/31 16:00:29 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*int main(void)
{
    int i;
    char str[] = "alexis";

    i = 0;
    while (str[i])
    {
        str[i] = toupper(str[i]);
        i++;
    }
    printf("%s", str);
}*/
