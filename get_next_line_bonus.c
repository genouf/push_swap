/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:12 by genouf            #+#    #+#             */
/*   Updated: 2022/05/25 16:43:22 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

size_t	ft_strlcpy_gnl(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize != 0)
	{
		i = 0;
		while (i + 1 < dstsize && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen_gnl(src));
}

int	ft_find_line(char *buff, int buff_size)
{
	int	i;

	i = 0;
	while (buff[i] && i < buff_size)
	{
		if (buff[i] == '\n')
		{
			return (i);
		}	
		i++;
	}
	return (-1);
}

char	*initialize_buff(int *ret, char *save, int fd)
{
	char	*new_buff;
	int		i;

	i = -1;
	new_buff = (char *)ft_calloc_gnl(sizeof(char), (6 + 1));
	if (new_buff == NULL)
		return (NULL);
	if (save[0] != '\0')
	{
		ft_strlcpy_gnl(new_buff, save, 6 + 1);
		while (++i < 6 + 1)
			save[i] = '\0';
		*ret = 1;
	}
	else
	{
		*ret = read(fd, new_buff, 6);
		if (*ret <= 0)
		{
			free(new_buff);
			return (NULL);
		}	
	}
	return (new_buff);
}

char	*process_line(char *result, char *buff, int	*ret, int fd)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	while (*ret && ft_find_line(buff, 6) == -1)
	{
		tmp = result;
		result = ft_strjoin_gnl(tmp, buff);
		*ret = read(fd, buff, 6);
		if (*ret == -1)
			return (free(tmp), free(result), NULL);
		buff[*ret] = '\0';
		free(tmp);
	}
	if (ret)
	{
		tmp = ft_subuff_gnl(buff, ft_find_line(buff, 6));
		tmp2 = result;
		result = ft_strjoin_gnl(result, tmp);
		free(tmp);
		free(tmp2);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char			*result;
	static char		save[6 + 1];
	char			*buff;
	int				ret;

	if (6 < 1 || fd < 0 || (read(fd, 0, 0) <= -1))
		return (NULL);
	result = NULL;
	buff = initialize_buff(&ret, save, fd);
	if (buff == NULL)
		return (NULL);
	result = process_line(result, buff, &ret, fd);
	if (ret)
		ft_substr_gnl(buff, ft_find_line(buff, 6 + 1), save);
	free(buff);
	return (result);
}
