/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:29:35 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/18 13:06:32 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_enemy_dir_img(t_map *map, int dir, void *img)
{
	map->enm_direction = dir;
	map->img_enemy = img;
}

int	draw_frame( t_map *map)
{
	if (map->frame_count % 10 == 0)
		enemy_move(map);
	if (map->frame_count % 44 == 0)
		map->img_collective = map->xpm_img_collective_r;
	else if (map->frame_count % 44 == 44 / 2)
		map->img_collective = map->xpm_img_collective_l;
	if (map->p_y == map->enm_y && map->p_x == map->enm_x)
	{
		free_arr(map->arr2d, map->height + 1);
		close(map->fd);
		destroy_images_window(map);
		exit(0);
	}
	set_objects_on_map(map);
	map->frame_count++;
	return (0);
}

int	path_enmy_is_valid(t_map *map, int x, int y)
{
	return ((map->arr2d[y][x] == '0' && map->arr2d[y][x - 1] != '1')
		|| (map->arr2d[y][x] == '0' && map->arr2d[y][x + 1] != '1')
		|| (map->arr2d[y][x] == '0' && map->arr2d[y + 1][x] != '1')
		|| (map->arr2d[y][x] == '0' && map->arr2d[y - 1][x] != '1'));
}

int	initialize_enemy(t_map *map)
{
	int	i;
	int	j;

	i = map->height / 2;
	while (i != (map->height / 2) - 1)
	{
		j = map->width / 2;
		while (j != (map->width / 2) - 1)
		{
			if (path_enmy_is_valid(map, j, i))
			{
				map->enm_x = j;
				map->enm_y = i;
				return (1);
			}
			j++;
			if (j == map->width)
				j = 0;
		}
		i++;
		if (i == map->height)
			i = 0;
	}
	return (0);
}

void	enemy_move(t_map *map)
{
	int	x;
	int	y;

	x = map->enm_x;
	y = map->enm_y;
	if (map->arr2d[y][x + 1] != '1' && map->enm_direction == 0)
		map->enm_x++;
	else if (map->arr2d[y][x + 1] == '1' && map->enm_direction == 0)
		set_enemy_dir_img(map, 3, map->xpm_img_enemy_l);
	if (map->arr2d[y][x - 1] != '1' && map->enm_direction == 1)
		map->enm_x--;
	else if (map->arr2d[y][x - 1] == '1' && map->enm_direction == 1)
		set_enemy_dir_img(map, 2, map->xpm_img_enemy_r);
	if (map->arr2d[y + 1][x] != '1' && map->enm_direction == 2)
		map->enm_y++;
	else if (map->arr2d[y + 1][x] == '1' && map->enm_direction == 2)
		map->enm_direction = 0;
	if (map->arr2d[y - 1][x] != '1' && map->enm_direction == 3)
		map->enm_y--;
	else if (map->arr2d[y - 1][x] == '1' && map->enm_direction == 3)
		map->enm_direction = 1;
}
