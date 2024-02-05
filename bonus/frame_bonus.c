/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:36:02 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/18 13:07:43 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_fd_destroy(t_map *map)
{
	close(map->fd);
	destroy_images_window(map);
}

void	player_move(int keycode, t_map *map)
{
	if (keycode == 0 || keycode == 123)
		map->p_x -= 1;
	else if (keycode == 13 || keycode == 126)
		map->p_y -= 1;
	else if (keycode == 2 || keycode == 124)
		map->p_x += 1;
	else if (keycode == 1 || keycode == 125)
		map->p_y += 1;
	else if (keycode == 53)
	{
		free_arr(map->arr2d, map->height + 1);
		close(map->fd);
		destroy_images_window(map);
		exit(0);
	}
	if ((keycode >= 0 && keycode <= 2) || keycode == 13
		|| (keycode >= 123 && keycode <= 126))
		map->p_move++;
}

void	print_player_move(t_map *map)
{
	char	*counter;

	counter = ft_itoa(map->p_move);
	if (!counter)
	{
		free_arr(map->arr2d, map->height + 1);
		close(map->fd);
		destroy_images_window(map);
		exit(0);
	}
	mlx_string_put(map->mlx, map->mlx_win, 10, 10, 0X000000, counter);
	free(counter);
}

void	player_on_wall(t_map *map, int old_x, int old_y)
{
	if (map->arr2d[map->p_y][map->p_x] == '1')
	{
		map->p_x = old_x;
		map->p_y = old_y;
		map->p_move -= 1;
	}
}

int	frame(int keycode, t_map *map)
{
	int	x;
	int	y;

	x = map->p_x;
	y = map->p_y;
	player_move(keycode, map);
	player_on_wall(map, x, y);
	if (map->arr2d[map->p_y][map->p_x] == 'C')
	{
		map->arr2d[map->p_y][map->p_x] = '0';
		map->n_c--;
		map->img_player = map->xpm_img_player_eat;
	}
	else
		map->img_player = map->xpm_img_player;
	if (map->n_c == 0)
		map->img_door = map->xpm_img_door_o;
	if ((map->n_c == 0 && map->arr2d[map->p_y][map->p_x] == 'E')
		|| (map->p_y == map->enm_y && map->p_x == map->enm_x))
	{
		free_arr(map->arr2d, map->height + 1);
		close_fd_destroy(map);
		exit(0);
	}
	return (set_objects_on_map(map), 0);
}
