#include "raycasting.h"
# include <math.h>



void casting_ray(t_player *player, t_map *map)
{
    int x;

    x = 0;
    while (x < WIN_WIDHT )
    {
        player->camera_x = 2 * x / (double)WIN_WIDHT -1;
        player->ray_dir_x = player->dir_x + player->plane_x * player->camera_x;
        player->ray_dir_y = player->dir_y + player->plane_y * player->camera_x;
        player->map_x = (int)player->x;
        player->map_y = (int)player->y;
        player->delta_dist_x = fabs(1 / player->ray_dir_x);
		if (player->ray_dir_x == 0)
			 player->delta_dist_x = 1e30;
        player->delta_dist_y = fabs(1 / player->ray_dir_y);
		if (player->ray_dir_y == 0)
			 player->delta_dist_y = 1e30;
        calcul_step(player);
        dda(player, map->map);
        calcul_wall_distance(player);
        calcul_wall_height(player);
        set_pixel_map(player, map,  x);
        x++;
    }   
}
