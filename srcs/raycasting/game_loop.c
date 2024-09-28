#include "raycasting.h"

int game_loop(t_all *all)
{
    if (ft_create_pixel_map(all->player) == false)
        return (1);
    casting_ray(all->player, all->map);
    return(0);
}