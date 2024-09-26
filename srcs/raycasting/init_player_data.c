
#include "raycasting.h"

void init_player_data(t_player *player)
{

    player->x = 2;
    player->y = 4;
    player->dir_x = 1;
    player->dir_y = 1;
    player->plane_x = 0.66;
    player->plane_y = 0.00;    
    int i = -1;
    while (++i < 4)
    {
        player->texture_buffer[i] = ft_calloc(NUM_TEXTURES,sizeof(int));
    }
     player->texture_buffer[1][1] = 0xFFFFFF;
     player->texture_buffer[2][1] = 0x000000;

}

