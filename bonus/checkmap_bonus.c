/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:36:19 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/18 12:42:44 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_border(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->arr2d[0][i] != '1' || map->arr2d[map->height - 1][i] != '1')
		{
			free_arr(map->arr2d, map->height + 1);
			print_error_and_exit(map, "border problem");
		}
		i++;
	}
	i = 1;
	while (i < map->height)
	{
		if (map->arr2d[i][0] != '1' || map->arr2d[i][map->width - 1] != '1')
		{
			printf("hani2\n");
			free_arr(map->arr2d, map->height + 1);
			print_error_and_exit(map, "border problem");
		}
		i++;
	}
}

void	all_line_same(t_map *map)
{
	int	i;

	i = 1;
	while (map->arr2d[i])
	{
		if (ft_strlen(map->arr2d[i]) != map->width)
		{
			free_arr(map->arr2d, map->height + 1);
			print_error_and_exit(map, "invalid line");
		}
		i++;
	}
}

void	is_valid_object(t_map *map, char c, int *n_p, int *n_e)
{
	if (c == 'C')
		map->n_c += 1;
	else if (c == 'P')
		*n_p += 1;
	else if (c == 'E')
		*n_e += 1;
	else if (c != '1' && c != '0')
	{
		free_arr(map->arr2d, map->height + 1);
		print_error_and_exit(map, "invalid character");
	}
}

int	check_objects(t_map *map)
{
	int	i;
	int	j;
	int	n_p;
	int	n_e;

	i = -1;
	n_p = 0;
	n_e = 0;
	map->n_c = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			is_valid_object(map, map->arr2d[i][j], &n_p, &n_e);
			if (map->arr2d[i][j] == 'P')
			{
				map->p_x = j;
				map->p_y = i;
			}
		}
	}
	if (map->n_c <= 0 || n_p != 1 || n_e != 1)
		return (0);
	return (1);
}

void	check_map(t_map *map, int fd)
{
	set_map_2d_arr(map, fd);
	if (map->height == map->width || map->height > 23 || map->width > 42)
		print_error_and_exit(map, "width == height");
	check_border(map);
	all_line_same(map);
	if (!check_objects(map))
	{
		free_arr(map->arr2d, map->height + 1);
		print_error_and_exit(map, "object more or less than we want");
	}
	is_items_reached(map, dup_map_arr2d(map));
}
