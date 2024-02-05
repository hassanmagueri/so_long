/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:35:19 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/18 10:09:24 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_bzero_nl(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*((unsigned char *)s + i++) = 0;
}

void	shift_it(char *s, int n)
{
	int	i;

	i = 0;
	if (n == -1)
		n = BUFFER_SIZE;
	while (s[i + n])
	{
		s[i] = s[i + n + 1];
		i++;
	}
	while (s[i])
		s[i++] = 0;
}

int	has_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*wanted_line(int fd, char *buffer, char *res, int nl_index)
{
	int	nl_infirst;
	int	size;
	int	i;

	i = 0;
	size = BUFFER_SIZE;
	nl_infirst = 0;
	if (nl_index != -1)
	{
		shift_it(buffer, nl_index);
		nl_infirst = 1;
	}
	while (nl_index == -1 && size == BUFFER_SIZE)
	{
		ft_bzero_nl(buffer, BUFFER_SIZE);
		size = read(fd, buffer, BUFFER_SIZE);
		nl_index = has_newline(buffer);
		res = ft_strjoin_nl(res, buffer, nl_index + 1);
		if (i++ > 7 || !res)
			return (free(res), NULL);
	}
	if (nl_infirst == 0)
		shift_it(buffer, nl_index);
	return (res);
}

char	*get_next_line(int fd, char *msg)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	int			nl_index;
	char		*res;
	char		c;

	res = NULL;
	if (fd < 0 || fd > OPEN_MAX || read(fd, &c, 0) < 0
		|| BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
	{
		if (! (fd < 0 || fd > OPEN_MAX))
			ft_bzero_nl(buffer[fd], BUFFER_SIZE);
		return (NULL);
	}
	buffer[fd][BUFFER_SIZE] = 0;
	nl_index = has_newline(buffer[fd]);
	res = ft_strjoin_nl(res, buffer[fd], nl_index + 1);
	if (!res)
		return (NULL);
	res = wanted_line(fd, buffer[fd], res, nl_index);
	if (!res)
		return (ft_bzero_nl(buffer, BUFFER_SIZE), NULL);
	if (*res == '\0')
		return (ft_bzero_nl(buffer, BUFFER_SIZE), free(res), *msg = 'a', NULL);
	return (res);
}
