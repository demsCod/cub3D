/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:37:45 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/07 16:13:41 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"
#include "errors/error.h"
#include "libft/libft.h"

int	quit(t_all *all)
{
	free_all_exit(EXIT_SUCCESS, all);
	return (0);
}

bool	create_text(t_img_data *img, t_map *map, t_cardinal_direction dir)
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

void	init_texture_buffer(t_map *map, t_player *player, t_windows *win)
{
	t_img_data	tmp;
	int			i;

	(void)player;
	if (win->mlx_ptr == NULL)
		free_all_exit(EXIT_FAILURE, map->all);
	map->path_texture[0] = ft_strdup(map->no_texture);
	map->path_texture[1] = ft_strdup(map->so_texture);
	map->path_texture[2] = ft_strdup(map->ea_texture);
	map->path_texture[3] = ft_strdup(map->we_texture);
	i = -1;
	while (++i < 4)
	{
		tmp.img = mlx_xpm_file_to_image(win->mlx_ptr,
				map->path_texture[i], &tmp.width, &tmp.height);
		if (!tmp.img)
			free_all_exit(EXIT_FAILURE, map->all);
		tmp.addr = (int *)mlx_get_data_addr(tmp.img,
				&tmp.bpp, &tmp.line_len, &tmp.endian);
		create_text(&tmp, map, i);
		mlx_destroy_image(win->mlx_ptr, tmp.img);
	}
}

int	start_game(t_map *map)
{
	t_windows	window;
	t_player	player;
	t_all		all;

	ft_bzero(&all, sizeof(t_all));
	ft_bzero(&player, sizeof(t_player));
	player.all = &all;
	map->all = &all;
	all.map = map;
	all.player = &player;
	init_player_data(&player, map->map);
	window.mlx_ptr = mlx_init();
	all.player->mlx_ptr = window.mlx_ptr;
	init_texture_buffer(map, &player, &window);
	window.win_ptr = mlx_new_window(window.mlx_ptr, WIN_WIDHT, WIN_HEIGHT,
			"CUB 3D");
	all.player->win_ptr = window.win_ptr;
	if (!window.win_ptr)
		free_all_exit(EXIT_FAILURE, &all);
	game_loop(&all);
	mlx_hook(window.win_ptr, 02, (1L << 0), ft_key_function, &all);
	mlx_hook(window.win_ptr, 17, (0L), *quit, &all);
	mlx_loop_hook(window.mlx_ptr, game_loop, &all);
	mlx_loop(window.mlx_ptr);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (EXIT_FAILURE);
	ft_bzero(&map, sizeof(t_map));
	map.map_fd = -1;
	map.cei_texture = -1;
	map.flo_texture = -1;
	if (get_map(&map, av[1]) == EXIT_FAILURE)
		free_and_exit(EXIT_FAILURE, &map);
	start_game(&map);
	return (EXIT_SUCCESS);
}
