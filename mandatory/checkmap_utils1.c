/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:36:19 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/18 11:48:47 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_arr(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(arr[i++]);
	free(arr);
}

char	**dup_map_arr2d(t_map *map)
{
	int		i;
	char	**arr;

	i = 0;
	arr = malloc(sizeof(char *) * (map->height + 1));
	if (!arr)
	{
		close(map->fd);
		destroy_images(map);
		exit(0);
	}
	while (i < map->height)
	{
		arr[i] = ft_strdup(map->arr2d[i]);
		if (!arr[i])
		{
			close(map->fd);
			free_arr(arr, i);
			destroy_images(map);
			exit(0);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

void	read_and_set(t_map *map, char **res, int fd, int *height)
{
	char	*tmp1;
	char	*tmp2;
	char	msg;

	msg = 'l';
	tmp1 = get_next_line(fd, &msg);
	if (!tmp1)
		free_print_error_exit(map, (*res), "width problem or alloc prob");
	*height = 0;
	while (tmp1 && msg == 'l')
	{
		tmp2 = (*res);
		(*res) = ft_strjoin(tmp2, tmp1);
		free(tmp1);
		if (!(*res))
			double_free_print_error_exit(map, *res, tmp2, "allocation problem");
		free(tmp2);
		tmp1 = get_next_line(fd, &msg);
		if (!tmp1 && msg == 'l')
			free_print_error_exit(map, *res, "allocation problem");
		if (*height > 23)
			double_free_print_error_exit(map, *res,
				tmp1, "alloc prob or more than max height");
		*height += 1;
	}
}

void	set_map_2d_arr(t_map *map, int fd)
{
	char	*res;
	int		height;

	res = NULL;
	height = 0;
	res = ft_strdup("");
	if (!res)
		print_error_and_exit(map, "allocation problem");
	read_and_set(map, &res, fd, &height);
	map->arr2d = ft_split(res, '\n');
	free(res);
	if (!map->arr2d)
		free_print_error_exit(map, res, "allocation problem");
	map->height = height;
	map->width = ft_strlen(map->arr2d[0]);
}
