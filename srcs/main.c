/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:37:45 by ibaby             #+#    #+#             */
/*   Updated: 2024/10/30 20:23:02 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"


void init_gun(t_all *all);

typedef struct s_windows
{
	void *mlx_ptr;
	void *win_ptr;
} t_windows;

bool	create_texture_from_img(t_img_data *img, t_map *map, t_cardinal_direction dir)
{
	int	*pixels;
	int	i;
	int	j;

	pixels = ft_calloc(sizeof(int), img->width * img->height);
	if (!pixels)
		return (false);
	i = -1;
	while (++i < img->height)
	{
		j = -1;
		while (++j < img->width)
			pixels[i * img->width + j] = img->addr[i * img->width + j];
	}
	map->texture_buffer[dir] = pixels;
	return (true);
}


void init_texture_buffer(t_map *map, t_player *player, t_windows *win)
{
	t_img_data	tmp;
	int		i;

	(void)player;
	//map->texture_buffer = malloc(sizeof(int ) * 5);
	map->path_texture[0] = ft_strdup (map->NO_texture);
	map->path_texture[1] = ft_strdup (map->SO_texture);
	map->path_texture[2] = ft_strdup (map->EA_texture);
	map->path_texture[3] = ft_strdup (map->WE_texture);
	i = -1;
	while (++i < 4)
	{
		tmp.img = mlx_xpm_file_to_image(win->mlx_ptr,
				map->path_texture[i], &tmp.width, &tmp.height);
		if (!tmp.img)
			exit(i);
		printf("%d | %d\n", tmp.height, tmp.width);
		tmp.addr = (int *)mlx_get_data_addr(tmp.img,
				&tmp.bpp, &tmp.line_len, &tmp.endian);
		create_texture_from_img(&tmp, map, i);
		mlx_destroy_image(win->mlx_ptr, tmp.img);
	}
}


int	main(int ac, char **av)
{
	t_map		map;
	t_windows 	window;
	t_player	*player;
	t_all 		*all;

	if (ac != 2)
		return (EXIT_FAILURE);
	player = malloc(sizeof(t_player));
	all = malloc(sizeof(t_all));
	ft_bzero(&map, sizeof(t_map));
	map.map_fd = -1;
	map.cei_texture = -1;
	map.flo_texture = -1;
	if (get_map(&map, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_player_data(player, map.map);
	all->map = &map;
	all->player = player;
	window.mlx_ptr = mlx_init();
    window.win_ptr = mlx_new_window(window.mlx_ptr, WIN_WIDHT, WIN_HEIGHT, "CUB 3D");
	init_texture_buffer(&map, player, &window);
	all->player->mlx_ptr = window.mlx_ptr;
	all->player->win_ptr = window.win_ptr;
	init_gun(all);
	game_loop(all);
	mlx_hook(window.win_ptr,  02, (1L << 0), keyfonction, all);
	mlx_loop_hook(window.mlx_ptr, game_loop, all);
    mlx_loop(window.mlx_ptr);
	return (EXIT_SUCCESS);
}


