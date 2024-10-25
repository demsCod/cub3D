#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../../includes/cub3D.h"
# include "../../includes/includes.h"
# include "../../includes/struct.h"

void	init_player_data(t_player *player);
void	calcul_step(t_player *player);
void	dda(t_player *player, char **map);
void	casting_ray(t_player *player, t_map *map);
int		game_loop(t_all *all);
void	calcul_wall_distance(t_player *player);
void	calcul_wall_height(t_player *player);
void	set_pixel_map(t_player *player, t_map *map, int x);
int		ft_create_pixel_map(t_player *player);
void	ft_draw_pixel_map(t_player *player, t_map *, t_all *all);
int		keyfonction(int keycode, t_all *data);
#endif