/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:37:45 by ibaby             #+#    #+#             */
/*   Updated: 2024/10/25 15:50:39 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"



int	main(int ac, char **av)
{
	t_map		map;
	t_all 		all;

	if (ac != 2)
		return (EXIT_FAILURE);
	ft_bzero(&map, sizeof(t_map));
	map.map_fd = -1;
	map.cei_texture = -1;
	map.flo_texture = -1;
	if (get_map(&map, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_game_data(&all, &map) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


