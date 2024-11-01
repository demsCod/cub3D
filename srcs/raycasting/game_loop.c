#include "raycasting.h"

void draw_gun(t_all *all);


void free_2d_tab_int(int **tab, int index)
{
	int i = 0;
	while (index > 0)
	{
		free(tab[i]);
		--index;
		i++;
	}
}


int game_loop(t_all *all)
{
	int i;

    i = ft_create_pixel_map(all->player);
	if (i == -1)
        free_all_exit(all);
    casting_ray(all->player, all->map);
    ft_draw_pixel_map(all->player, all->map, all);
	free_2d_tab_int(all->player->pixel_map, i);
    return (0);
}