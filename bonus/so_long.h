/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emagueri <emagueri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:41:54 by emagueri          #+#    #+#             */
/*   Updated: 2024/01/16 10:22:42 by emagueri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <limits.h>
# define BUFFER_SIZE 10

typedef struct s_map
{
	int				width;
	int				height;
	int				fd;
	int				p_x;
	int				p_y;
	int				n_c;
	int				p_move;
	int				enm_x;
	int				enm_y;
	int				enm_direction;
	int				items_count;
	unsigned long	frame_count;
	void			*img_collective;
	void			*xpm_img_collective_r;
	void			*xpm_img_collective_l;
	void			*img_enemy;
	void			*xpm_img_enemy_r;
	void			*xpm_img_enemy_l;
	void			*img_player;
	void			*xpm_img_player;
	void			*xpm_img_player_eat;
	void			*img_door;
	void			*xpm_img_door_c;
	void			*xpm_img_door_o;
	void			*xpm_img_wall;
	void			*xpm_background;
	void			*mlx;
	void			*mlx_win;
	char			**arr2d;
}	t_map;

void	print_error_and_exit(t_map *map, char *msg);
void	free_print_error_exit(t_map *map, void *ptr, char *msg);
void	check_map(t_map *map, int fd);
void	set_objects_on_map(t_map *map);
int		frame(int keycode, t_map *map);
void	free_arr(char **arr, int len);
int		count_spliter(char *s, int c);
void	free_arr(char **arr, int len);
char	**dup_map_arr2d(t_map *map);
void	read_and_set(t_map *map, char **res, int fd, int *height);
void	set_map_2d_arr(t_map *map, int fd);
void	check_border(t_map *map);
void	all_line_same(t_map *map);
void	is_valid_object(t_map *map, char c, int *n_p, int *n_e);
void	flood_fill(t_map *map, char **arr, int x, int y);
void	is_items_reached(t_map *map, char **arr);
void	check_map(t_map *map, int fd);
int		draw_frame( t_map *map);
void	enemy_move(t_map *map);
int		initialize_enemy(t_map *map);
void	print_player_move(t_map *map);
void	my_mlx_xpm_to_image(t_map *map, void *img, int x, int y);
void	set_objects_on_map(t_map *map);
void	set_enemy_dir_img(t_map *map, int dir, void *img);
void	initialize_objects(t_map *map);
void	double_free_print_error_exit(t_map *map, void *p1, void *p2, char *m);
int		is_valid_map_path(char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
char	*ft_strjoin_nl(char const *s1, char const *s2, int lens2);
int		ft_strlen_nl(const char *str);
void	ft_bzero_nl(void *s, size_t n);
char	*get_next_line(int fd, char *msg);
void	free_it(char *str);
char	*wanted_line(int fd, char *buffer, char *res, int nl_index);

#endif