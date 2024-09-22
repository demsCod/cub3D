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

typedef struct s_windows
{
	void *mlx_ptr;
	void *win_ptr;
} t_windows;

int	main(int ac, char **av)
{
	t_map		map;
	t_windows 	window;
	t_player	player;
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
/******************************************************************************************************************************************** */	
	window.mlx_ptr = mlx_init();
    window.win_ptr = mlx_new_window(window.mlx_ptr, 640, 360, "Tutorial Window");
	init_player_data(&player);
    mlx_loop(window.mlx_ptr);
	
	(void)window.win_ptr;
	free_and_exit(EXIT_SUCCESS, &map);
	return (EXIT_SUCCESS);
}
