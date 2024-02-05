/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 04:35:16 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/17 23:07:34 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_it(char *str)
{
	if (str)
		free((void *)str);
	str = NULL;
}

char	*ft_strjoin_nl(char const *s1, char const *s2, int lens2)
{
	char	*res;
	int		i;
	int		size;
	int		lens1;

	if (lens2 == 0)
		lens2 = ft_strlen_nl(s2);
	lens1 = ft_strlen_nl((char *)s1);
	size = lens2 + lens1 + 1;
	res = malloc(size);
	if (!res)
	{
		free((char *)s1);
		return (NULL);
	}
	i = -1;
	while (++i < lens1)
		res[i] = s1[i];
	while (s2[i - lens1] && i < size - 1)
	{
		res[i] = s2[i - lens1];
		i++;
	}
	res[i] = 0;
	return (free((char *)s1), res);
}

int	ft_strlen_nl(const char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}
