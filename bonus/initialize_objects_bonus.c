/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_objects_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:24:04 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/18 13:14:30 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images(t_map *map)
{
	mlx_destroy_image(map->mlx, map->xpm_img_collective_l);
	mlx_destroy_image(map->mlx, map->xpm_img_door_c);
	mlx_destroy_image(map->mlx, map->xpm_img_door_o);
	mlx_destroy_image(map->mlx, map->xpm_img_player);
	mlx_destroy_image(map->mlx, map->xpm_img_player_eat);
	mlx_destroy_image(map->mlx, map->xpm_img_wall);
	mlx_destroy_image(map->mlx, map->xpm_background);
}

void	destroy_images_window(t_map *map)
{
	destroy_images(map);
	mlx_destroy_window(map->mlx, map->mlx_win);
}

void	*mm(t_map *map, char *file_name, void *images[], int i)
{
	int		n;
	void	*img_p;

	img_p = mlx_xpm_file_to_image(map->mlx, file_name, &n, &n);
	if (!img_p)
	{
		while (i--)
			mlx_destroy_image(map->mlx, images[i]);
		print_error_and_exit(map, "invalid image");
	}
	return (img_p);
}

void	set_xpm_images(t_map *map, void *imgs[])
{
	map->xpm_img_collective_r = mm(map,
			"./bonus/textures/apple_r-39.xpm", imgs, 0);
	imgs[0] = map->xpm_img_collective_r;
	map->xpm_img_collective_l = mm(map,
			"./bonus/textures/apple_r39.xpm", imgs, 1);
	imgs[1] = map->xpm_img_collective_l;
	map->xpm_img_door_c = mm(map, "./bonus/textures/closed_door.xpm", imgs, 2);
	imgs[2] = map->xpm_img_door_c;
	map->xpm_img_door_o = mm(map, "./bonus/textures/opned_door.xpm", imgs, 3);
	imgs[3] = map->xpm_img_door_o;
	map->xpm_img_player = mm(map, "./bonus/textures/player.xpm", imgs, 4);
	imgs[4] = map->xpm_img_player;
	map->xpm_img_player_eat = mm(map,
			"./bonus/textures/player_eat.xpm", imgs, 5);
	imgs[5] = map->xpm_img_player_eat;
	map->xpm_img_wall = mm(map, "./bonus/textures/wall.xpm", imgs, 6);
	imgs[6] = map->xpm_img_wall;
	map->xpm_img_enemy_l = mm(map, "./bonus/textures/kira_L.xpm", imgs, 7);
	imgs[7] = map->xpm_img_enemy_l;
	map->xpm_img_enemy_r = mm(map, "./bonus/textures/kira_R.xpm", imgs, 8);
	imgs[8] = map->xpm_img_enemy_r;
	map->xpm_background = mm(map, "./bonus/textures/background.xpm", imgs, 9);
	imgs[9] = map->xpm_background;
}

void	initialize_objects(t_map *map)
{
	void	*images[10];

	map->n_c = 0;
	map->frame_count = 0;
	map->p_move = 0;
	map->height = 0;
	map->width = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->enm_x = 0;
	map->enm_y = 0;
	map->enm_direction = 0;
	set_xpm_images(map, images);
	map->img_door = map->xpm_img_door_c;
	map->img_enemy = map->xpm_img_enemy_l;
	map->img_player = map->xpm_img_player;
	map->img_collective = map->xpm_img_collective_l;
}
