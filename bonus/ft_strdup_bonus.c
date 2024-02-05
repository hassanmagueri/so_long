/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:04:02 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/17 23:07:21 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	res = malloc(len * sizeof(char) + 1);
	if (!res)
		return (0);
	res[len] = 0;
	while (len--)
		res[len] = s1[len];
	return (res);
}
