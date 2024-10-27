#include "../../includes/cub3D.h"


void open_windows(t_all *all, t_map *map)
{
    (void)map;
    all->mlx_p = mlx_init();
    all->win_p =  mlx_new_window(all->mlx_p, S_W, S_H, "CUB 3D");
    mlx_key_hook(all->mlx_p, keyfonction, all);
    mlx_loop(all->mlx_p);
}