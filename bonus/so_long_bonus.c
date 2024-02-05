/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:36:24 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/18 12:57:51 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_error_and_exit(t_map *map, char *msg)
{
	if (ft_strncmp(msg, "enter a correct map name", ft_strlen(msg)) != 0
		&& ft_strncmp(msg, "mlx fail", ft_strlen(msg)) != 0
		&& ft_strncmp(msg, "invalid image", ft_strlen(msg)) != 0)
		destroy_images(map);
	close(map->fd);
	ft_putendl_fd("error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	double_free_print_error_exit(t_map *map, void *p, void *p2, char *m)
{
	free(p);
	free_print_error_exit(map, p2, m);
}

void	free_print_error_exit(t_map *map, void *ptr, char *msg)
{
	free(ptr);
	print_error_and_exit(map, msg);
}

int	close_window(t_map *map)
{
	free_arr(map->arr2d, map->height + 1);
	close(map->fd);
	exit(0);
}

int	main(int ac, char **av)
{
	t_map	map;
	void	*p;

	if (ac != 2)
		print_error_and_exit(&map, "enter a correct map name");
	map.fd = open(av[1], O_RDWR);
	if (map.fd == -1 || !is_valid_map_path(av[1]))
		return (1);
	map.mlx = mlx_init();
	if (!map.mlx)
		print_error_and_exit(&map, "mlx fail");
	initialize_objects(&map);
	check_map(&map, map.fd);
	initialize_enemy(&map);
	p = mlx_new_window(map.mlx, map.width * 60, map.height * 60, "so_long");
	if (!p)
		print_error_and_exit(&map, "mlx win fail");
	map.mlx_win = p;
	set_objects_on_map(&map);
	mlx_hook(map.mlx_win, 2, 0, frame, &map);
	mlx_hook(map.mlx_win, 17, 0, close_window, &map);
	mlx_loop_hook(map.mlx, draw_frame, &map);
	mlx_loop(map.mlx);
	close(map.fd);
}
