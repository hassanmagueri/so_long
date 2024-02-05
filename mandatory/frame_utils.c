/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:31:27 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/18 10:08:20 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_xpm_to_image(t_map *map, void *img, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, x, y);
}

void	set_objects_on_map(t_map *map)
{
	int	i;
	int	j;

	mlx_clear_window(map->mlx, map->mlx_win);
	my_mlx_xpm_to_image(map, map->xpm_background, 0, 0);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->arr2d[i][j] == '1')
				my_mlx_xpm_to_image(map, map->xpm_img_wall, j * 60, i * 60);
			else if (map->arr2d[i][j] == 'C')
				my_mlx_xpm_to_image(map, map->img_collective, j * 60, i * 60);
			else if (map->arr2d[i][j] == 'E')
				my_mlx_xpm_to_image(map, map->img_door, j * 60, i * 60);
			j++;
		}
		i++;
	}
	my_mlx_xpm_to_image(map, map->img_player, map->p_x * 60, map->p_y * 60);
}
