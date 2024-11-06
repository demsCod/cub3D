/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:33:40 by mdembele          #+#    #+#             */
/*   Updated: 2024/11/06 13:24:01 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	free_2d_tab_int(int **tab, int index)
{
	int	i;

	i = 0;
	while (index > 0)
	{
		free(tab[i]);
		--index;
		i++;
	}
}

int	game_loop(t_all *all)
{
	int	i;

	i = ft_create_pixel_map(all->player);
	if (i == -1)
		free_all_exit(EXIT_FAILURE, all);
	casting_ray(all->player, all->map);
	ft_draw_pixel_map(all->player, all->map);
	free_2d_tab_int(all->player->pixel_map, i);
	return (0);
}
