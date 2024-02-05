/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:36:19 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/17 23:07:15 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count + 1);
}

static char	*ft_strsdup(char const *s, int *index, char c)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != c && s[len])
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	*index += i;
	return (str);
}

static char	**freetab(char **res, int i)
{
	while (i--)
		free(res[i]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		index;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	res = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < count_word(s, c))
	{
		if (i != 0)
			index++;
		res[i] = ft_strsdup(s + index, &index, c);
		if (!res[i])
			return (freetab(res, i));
		i++;
	}
	res[i] = NULL;
	return (res);
}
