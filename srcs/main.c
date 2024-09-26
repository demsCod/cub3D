/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:37:45 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/18 21:03:44 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// int	keyfonction(int keycode, t_map_data *data);

typedef struct s_windows
{
	void *mlx_ptr;
	void *win_ptr;
} t_windows;

int	main(int ac, char **av)
{
	t_map		map;
	t_windows 	window;
	t_player	*player;
	t_all 		*all;

	player = malloc(sizeof(t_player));
	all = malloc(sizeof(t_all));
	if (ac != 2)
		return (EXIT_FAILURE);
	ft_bzero(&map, sizeof(t_map));
	if (get_map(&map, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	printf("infos:\n---------------------\nNO: [%s]\nSO: [%s]\nWE: [%s]\nEA: [%s]\nF: [%s]\nC: [%s]\n---------------------\n",
		map.NO_texture, map.SO_texture, map.WE_texture, map.EA_texture,
		map.flo_texture, map.cei_texture);
	printf("\nmap:\n---------------------\n");
	print_2d_array_nl(map.map);
	printf("\n---------------------\n");
	printf("\n %c \n", map.player_direction);
	printf("%s\n", map.cei_texture);
/******************************************************************************************************************************************** */	
	all->map = &map;
	init_player_data(player);
	all->player = player;
	window.mlx_ptr = mlx_init();
    window.win_ptr = mlx_new_window(window.mlx_ptr, WIN_WIDHT, WIN_HEIGHT, "Tutorial Window");
	all->player->mlx_ptr = window.mlx_ptr;
	all->player->win_ptr = window.win_ptr;
	game_loop(all);
	mlx_loop_hook(window.mlx_ptr, game_loop, all);
	// mlx_hook(window.mlx_ptr,  02, (1L << 0), keyfonction, all->player);
    mlx_loop(window.mlx_ptr);
	free_and_exit(EXIT_SUCCESS, &map);
	return (EXIT_SUCCESS);
}
