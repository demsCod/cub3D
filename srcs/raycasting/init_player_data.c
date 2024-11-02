/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:34:33 by mdembele          #+#    #+#             */
/*   Updated: 2024/11/02 16:41:40 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	define_lateral_margin(char **map, t_player *player, int x, int y)
{
	if (map[y][x - 1] && map[y][x - 1] == '1' && map[y][x + 1] && map[y][x
		+ 1] == '1')
	{
		player->x += WALL_MARGIN / 2;
		return ;
	}
	if (map[y][x + 1] && map[y][x + 1] == '1')
		player->x -= WALL_MARGIN;
	else if (map[y][x - 1] && map[y][x - 1] == '1')
		player->x += WALL_MARGIN;
}

void	define_vertical_margin(char **map, t_player *player, int x, int y)
{
	if (map[y - 1][x] && map[y - 1][x] == '1' && map[y + 1][x] && map[y
		+ 1][x] == '1')
	{
		player->y += WALL_MARGIN / 2;
		return ;
	}
	if (map[y + 1][x] && map[y + 1][x] == '1')
		player->y -= WALL_MARGIN;
	else if (map[y - 1][x] && map[y - 1][x] == '1')
		player->y += WALL_MARGIN;
}

void	define_pos(char **map, t_player *player, int x, int y)
{
	player->x = x;
	player->y = y;
	define_lateral_margin(map, player, x, y);
	define_vertical_margin(map, player, x, y);
}

void	player_pos(char **map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
			{
				player->initial_direction = map[y][x];
				define_pos(map, player, x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_player_data(t_player *player, char **map)
{
	player_pos(map, player);
	if (player->initial_direction == 'N')
	{
		free((player->dir_x = 0.0, player->dir_y = 1.0, NULL));
		player->plane_x = 0.66;
		player->plane_y = 0.00;
	}
	else if (player->initial_direction == 'S')
	{
		free((player->dir_x = 0.0, player->dir_y = -1.0, NULL));
		player->plane_x = -0.66;
		player->plane_y = 0.00;
	}
	else if (player->initial_direction == 'E')
	{
		free ((player->dir_x = -1, player->dir_y = 0.0, NULL));
		player->plane_x = 0.00;
		player->plane_y = 0.66;
	}
	else
	{
		free((player->dir_x = 1, player->dir_y = 0.0, NULL));
		player->plane_x = 0.00;
		player->plane_y = -0.66;
	}
}
