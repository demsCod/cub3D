
#include "raycasting.h"

void init_player_data(t_player *player)
{

    player->x = 4;
    player->y = 2;
    player->dir_x = -1;
    player->dir_y = 0.0;
    player->plane_x = 0.00;
    player->plane_y = 0.66;    
}

