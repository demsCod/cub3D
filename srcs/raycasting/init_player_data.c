
#include "raycasting.h"

void	player_pos(char **map, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	while(map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
			{
				player->initial_direction = map[y][x];
				player->x = x;
				if (map[y][x - 1] && map[y][x - 1] == '1')
					player->x += WALL_MARGIN;
				if (map[y][x + 1] && map[y][x + 1] == '1')
					player->x -= WALL_MARGIN;
				player->y = y;
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
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = 0.66;
		player->plane_y = 0.00;
	}
	else if (player->initial_direction == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = -0.66;
		player->plane_y = 0.00;
	}
	else if (player->initial_direction == 'E')
	{
		player->dir_x = -1;
		player->dir_y = 0.0;
		player->plane_x = 0.00;
		player->plane_y = 0.66;
	}
	else
	{
		player->dir_x = 1;
		player->dir_y = 0.0;
		player->plane_x = 0.00;
		player->plane_y = -0.66;
	}
}
