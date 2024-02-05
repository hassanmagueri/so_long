/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap_utils2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:36:19 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/17 23:16:11 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(t_map *map, char **arr, int x, int y)
{
	if (x < 0 || x > map->width - 1)
		return ;
	if (y < 1 || y > map->height - 1)
		return ;
	if (arr[y][x] == '1')
		return ;
	if (arr[y][x] == 'v')
		return ;
	if (arr[y][x] == 'C' || arr[y][x] == 'E')
		map->items_count += 1;
	arr[y][x] = 'v';
	flood_fill(map, arr, x + 1, y);
	flood_fill(map, arr, x - 1, y);
	flood_fill(map, arr, x, y + 1);
	flood_fill(map, arr, x, y - 1);
}

void	is_items_reached(t_map *map, char **arr)
{
	map->items_count = 0;
	flood_fill(map, arr, map->p_x, map->p_y);
	free_arr(arr, map->height + 1);
	if (map->items_count != map->n_c + 1)
	{
		free_arr(map->arr2d, map->height + 1);
		print_error_and_exit(map, "set a valid objects path");
	}
}

int	is_valid_map_path(char *s)
{
	int		i;
	char	*ext;

	i = ft_strlen(s) - 4;
	ext = ".ber";
	if (ft_strncmp((s + i), ext, 4))
		return (0);
	return (1);
}
