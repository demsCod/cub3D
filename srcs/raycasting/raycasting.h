/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdembele <mdembele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:35:56 by mdembele          #+#    #+#             */
/*   Updated: 2024/11/02 16:58:31 by mdembele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# define WALL_MARGIN 0.2
# define MOVE_SPEED 2.0
# define ROT_SPEED 1.3
# define MAX_DELTA 0.1
# include "../../includes/cub3D.h"
# include "../../includes/includes.h"
# include "../../includes/struct.h"

void	init_player_data(t_player *player, char **map);
void	calcul_step(t_player *player);
void	dda(t_player *player, char **map);
void	casting_ray(t_player *player, t_map *map);
int		game_loop(t_all *all);
void	calcul_wall_distance(t_player *player);
void	calcul_wall_height(t_player *player);
void	set_pixel_map(t_player *player, t_map *map, int x);
int		ft_create_pixel_map(t_player *player);
void	ft_draw_pixel_map(t_player *player, t_map *map);
int		ft_key_function(int keycode, t_all *data);
int		ft_move_right(t_player *r);
int		ft_move_left(t_player *r);
int		ft_try_move(t_player *r, t_map *map, double new_x, double new_y);
double	ft_get_delta(void);
void	ft_rotate_vectors(t_player *r, double rot_speed);
int		ft_is_wall(t_map *map, double x, double y);
#endif