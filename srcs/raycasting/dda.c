/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:27:58 by mdembele          #+#    #+#             */
/*   Updated: 2024/11/02 16:28:12 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include <math.h>

void	calcul_step(t_player *player)
{
	if (player->ray_dir_x < 0)
	{
		player->step_x = -1;
		player->side_dist_x = (player->x - player->map_x)
			* player->delta_dist_x;
	}
	else
	{
		player->step_x = 1;
		player->side_dist_x = (player->map_x + 1.0 - player->x)
			* player->delta_dist_x;
	}
	if (player->ray_dir_y < 0)
	{
		player->step_y = -1;
		player->side_dist_y = (player->y - player->map_y)
			* player->delta_dist_y;
	}
	else
	{
		player->step_y = 1;
		player->side_dist_y = (player->map_y + 1.0 - player->y)
			* player->delta_dist_y;
	}
}

void	dda(t_player *player, char **map)
{
	while (1)
	{
		if (player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_dist_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_dist_y;
			player->map_y += player->step_y;
			player->side = 1;
		}
		if (map[player->map_y][player->map_x] == '1')
			break ;
	}
}

void	calcul_wall_distance(t_player *player)
{
	if (player->side == 0)
		player->wall_dist = (player->map_x - player->x + (1 - player->step_x)
				/ 2) / player->ray_dir_x;
	else
		player->wall_dist = (player->map_y - player->y + (1 - player->step_y)
				/ 2) / player->ray_dir_y;
}

void	calcul_wall_height(t_player *player)
{
	player->line_height = (int)(WIN_HEIGHT / player->wall_dist);
	player->draw_start = -player->line_height / 2 + WIN_HEIGHT / 2;
	if (player->draw_start < 0)
		player->draw_start = 0;
	player->draw_end = player->line_height / 2 + WIN_HEIGHT / 2;
	if (player->draw_end >= WIN_HEIGHT)
		player->draw_end = WIN_HEIGHT - 1;
	if (player->side == 0)
		player->wall_x = player->y + player->wall_dist * player->ray_dir_y;
	else
		player->wall_x = player->x + player->wall_dist * player->ray_dir_x;
	player->wall_x -= floor(player->wall_x);
}
