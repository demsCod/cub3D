/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:37:45 by ibaby             #+#    #+#             */
/*   Updated: 2024/09/18 18:00:19 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (EXIT_FAILURE);
	ft_bzero(&map, sizeof(t_map));
	if (get_map(&map, av[1]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	printf("infos:\n---------------------\nNO: %s\nSO: %s\nWE: %s\nEA: %s\nF: %s\nC: %s\n---------------------\n",
		map.NO_texture, map.SO_texture, map.WE_texture, map.EA_texture,
		map.flo_texture, map.cei_texture);
	printf("\nmap:\n---------------------\n");
	print_2d_array(map.map);
	printf("\n---------------------\n");
	return (EXIT_SUCCESS);
}
