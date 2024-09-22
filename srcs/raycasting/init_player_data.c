
#include "raycasting.h"

void init_player_data(t_player *player)
{

    player->x = 1;
    player->y = 13;
    player->dir_x = 1;
    player->dir_y = -1;
    player->plane_x = 0.00;
    player->plane_y = 0.66;    
    int i = -1;
    while (++i < 4)
    {
        player->texture_buffer[i] = ft_calloc(1,sizeof(int));
    }
}

