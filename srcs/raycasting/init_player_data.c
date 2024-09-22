
#include "raycasting.h"

void init_player_data(t_player *player)
{
    player->pos.x = 22;
    player->pos.y = 12;
    player->dir.x = -1;
    player->dir.y = 0;
    player->plane.x = 0.00;
    player->plane.y = 0.66;    
    
    
}