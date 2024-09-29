#include "raycasting.h"

void draw_gun(t_all *all);

void init_gun(t_all *all)
{
    all->gun = malloc(sizeof(t_gun));
    all->gun->img = mlx_xpm_file_to_image(all->player->mlx_ptr, "/home/dems/Documents/Project42/cub3D/texture/gun_1.xpm", 
                                          &all->gun->width, &all->gun->height);
    all->gun->addr = mlx_get_data_addr(all->gun->img, &all->gun->bits_per_pixel, 
                                       &all->gun->line_length, &all->gun->endian);
}



int game_loop(t_all *all)
{
    if (ft_create_pixel_map(all->player) == false)
        return (1);
    casting_ray(all->player, all->map);
    ft_draw_pixel_map(all->player, all->map, all);
    return(0);
}